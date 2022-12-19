#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        array[i] = a;
    }

    sort(array.begin(), array.end());

    int max_frequency = 0;
    int max_frequent_element = -1;

    int current_element = array[0];
    int current_frequency = 1;

    for (int i = 1; i < array.size(); i++){
        if (array[i] == current_element){
            current_frequency++;
            continue;

        } else if (max_frequency <= current_frequency && max_frequent_element < current_element){
            max_frequency = current_frequency;
            max_frequent_element = current_element;

        }

        current_element = array[i];
        current_frequency = 1;


    }

    if (max_frequency <= current_frequency && max_frequent_element < current_element){
        max_frequency = current_frequency;
        max_frequent_element = current_element;
    }

    cout << max_frequent_element;

    
    return 0;
}