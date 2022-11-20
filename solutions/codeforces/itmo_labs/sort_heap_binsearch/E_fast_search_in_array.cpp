#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int leftmost_binary_search(vector<int>& array, int key, int size){
    // arr = [1, 2, 3, 3, 3, 6, 9]
    // check whether the target exists
    // arr[leftmost_binary_search(arr, 2)] == 2

    // find the leftmost index of the target if it exists
    // binarySearch(arr, 3) = 2
    // binarySearch(arr, 9) = 6

    // find the index of where the target should be if it doesn't exist
    // binarySearch(arr, 4) = 5
    // binarySearch(arr, -5) = 0
    // binarySearch(arr, 100) = 7


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

    return left;


}


int main(){
    int n;
    cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;

        int index_of_leftmost_l_value = leftmost_binary_search(array, l, n);
        int index_of_first_value_greater_than_r = leftmost_binary_search(array, r + 1, n);

        // cout << index_of_leftmost_l_value << ' ' << index_of_first_value_greater_than_r << '\n';
        cout << index_of_first_value_greater_than_r - index_of_leftmost_l_value << '\n';

    }

}