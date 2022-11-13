#include <iostream>
#include <vector>


using namespace std;


void countSort_stable(vector<int>& array, int decimal){

    const int MAX = 10;

    vector<int> output(array.size());
    vector<int> count(MAX, 0);

    for (int x: array){
        count[(x / decimal) % 10]++;
    }
    // count[k] == # of occurences of k in array
    
    for (int i = 1; i < MAX; i++){
        count[i] += count[i - 1];

    }
    //count[k] == # of occurences of all x <= k in array ==> count[k] - 1 == index where to place last occurence of k
    
    for (int i = array.size() - 1; i >=0; i--){
        output[count[(array[i] / decimal) % 10] - 1] = array[i]; // or can be executed as output[--count[(array[i] / decimal) % 10]] = array[i];
        count[(array[i] / decimal) % 10]--;
    }

    array = output;

}

void radixSort_stable(vector<int>& array){

    int max = array[0];
    for (int i = 1; i < array.size(); i++){
        if (array[i] > max){
            max = array[i];
        }
    }

    for (int decimal = 1; max / decimal > 0; decimal *= 10){
        countSort_stable(array, decimal);
    }


}