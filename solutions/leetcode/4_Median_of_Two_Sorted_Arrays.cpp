#include <vector>
#include <algorithm>
#include <limits>

using std::max;
using std::min;
using std::vector;


const int INF = std::numeric_limits<int>::max();
const int neg_INF = std::numeric_limits<int>::min();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if (n > m){
            
            return findMedianSortedArrays(nums2, nums1);
        }

        // now A is the smallest array and has length n
        // len(B) = m

        if (n == 0){
            double median = (m % 2 == 1) ? static_cast<double>(nums2[m/2]): static_cast<double>(nums2[m/2] + nums2[m/2-1]) / 2;
            return median;
        }


        int left = 0, right = n;
        
        int half = (m + n + 1) / 2;

        int A_left, A_right, B_left, B_right;
        while (true){

            int i = right + (left - right) / 2; // for nums1 which is always smaller
            int j = half - i; // index j is the index of (first) leftmost element in nums2 which is outside the partition

            A_left = (i > 0) ? nums1[i - 1] : -1000000;
            A_right = (i < n) ? nums1[i] : 1000000;

            B_left = (j > 0) ? nums2[j - 1] : -1000000;
            B_right = (j < m) ? nums2[j] : 1000000;
            
            
            cout << A_left << " " << A_right << " " << B_left << " " << B_right << "\n";
            if (A_left <= B_right && B_left <= A_right){
                if ((n + m) % 2 == 1){ // n + m is odd
                    return static_cast<double>(max(A_left, B_left)); // this difference due to the fact that we started from right = n and we rounded half => search for the partition longer then it is by 1 value in the even case => A_left and B_left are potential candidates for the leftmost position after partition window
                } else {
                    return static_cast<double>(max(A_left, B_left) + min(A_right, B_right)) / 2;
                }
            }

            if (A_left > B_right){
                right = i - 1; // reduce size of an array from A
            } else { // B_left > A_right 
                left = i + 1;
            }
        }

    }
};