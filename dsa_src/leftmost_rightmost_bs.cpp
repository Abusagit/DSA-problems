#include <tuple>
#include <vector>

using namespace std;

class Solution {
    public:
    
    tuple<int, int> searchRange( vector<int>& nums, int target) {

        int n = nums.size();

        int leftmost = n; 
        int left = 0, right = n - 1;

        // LEFTMOST
        while (left <= right) {
            int mid = (left + right) / 2; 

            if (nums[mid] < target) {
                left = mid + 1; 
            } else if (nums[mid] > target) {
                right = mid - 1; 

            } else {
                // binary search for leftmost index 
                leftmost = mid; 
                right = mid - 1; 
            }
        }


        int rightmost = -1;
        left = 0; right = n - 1;
        
        // RIGHTMOST
        while (left <= right) {
            int mid = (left + right) / 2; 
            if (nums[mid] < target) {
                left = mid + 1; 
            } else if (nums[mid] > target) {
                right = mid - 1; 
            } else {
                // binary search for rightmost index
                rightmost = mid; 
                left = mid + 1; 
            }
        }
        
        return make_tuple(leftmost, rightmost);
    }
};


int leftmost_binary_search(vector<int>& array, int key){
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
    int right = array.size() - 1;

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