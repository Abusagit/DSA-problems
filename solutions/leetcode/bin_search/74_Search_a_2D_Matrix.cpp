#include <vector>


using std::vector;



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int left = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int right = m * n - 1;

        while (left <= right){

            int middle = right + (left - right) / 2;

            // compute sub-indices using matrix structur)
            int row = middle / n;
            int col = middle % n; 


            //ordinary binary search
            int middle_x = matrix[row][col];
            if (target > middle_x){
                left = ++middle;
            } else if (target < middle_x){
                right = --middle;
            } else {
                return true;
            }


        }

        return false;
        
    }
};