#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int get_index_of_closest_value(vector<int>& array, int key, int size){

    int left = 0;
    int right = size - 1;

    while (left <= right){
        int middle = (left + right) / 2;


        if (array[middle] < key){
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }


    // left == index of the smallest element greater than or equal key
    // closest value procedure:
    if (array[left] != key && left > 0 && abs(array[left - 1] - key) <= abs(array[left] - key)){\
        // if array[left] is not 1st element AND key is not found AND array[left - 1] is not farther to key than array[left] -> return left - 1 b.c. it`s the closest
        return left - 1;
    }

    return left;

}


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> numbers(n);
    vector<int> queries(m);

    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    for (int i = 0; i < m; i++){
        cin >> queries[i];
    }

    for (int q: queries){
        int closest_i = get_index_of_closest_value(numbers, q, n);
        cout << numbers[closest_i] << '\n';
    }
    // cout << numbers[leftmost_binary_search(numbers, 5, n)];
}