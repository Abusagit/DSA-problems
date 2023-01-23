#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
using std::ceil;
using std::max_element;
using std::min;

// T(n) = O(len(piles) * (log_2(max_piles))
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int high_speed = *max_element(piles.begin(), piles.end());
        int low_speed = 1;
        
        int min_speed = high_speed;
        
        while (low_speed <= high_speed){
            int middle_speed = high_speed + (low_speed - high_speed) / 2;
            
            long hours_to_eat_all_bananas = 0;
            for (auto x: piles){
                hours_to_eat_all_bananas += ceil(static_cast<double>(x) / middle_speed);
            }
            
            if (hours_to_eat_all_bananas <= h){
                min_speed = min(min_speed, middle_speed);
                high_speed = middle_speed - 1;
                
            } else {
                low_speed = middle_speed + 1;
            }
            
            
        }
        
        return min_speed;

}

};