#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<pair<int, double>> pos_time;
        std::stack<pair<int, double>> stk;
        
        int pos;
        double time;
        pair<int, double> p;
        
        for (int i=0; i < position.size(); i++){
            pos = position[i]; 
            time = (target - pos) / static_cast<double>(speed[i]);
            
            pos_time.push_back({pos, time});
        }
        
        std::sort(pos_time.begin(), pos_time.end());
        
        
        double max_time = 0;
        int result = 0;
        
        for (vector<pair<int, double>>::iterator it=pos_time.end() - 1; it != pos_time.begin() - 1; it--){
            double time = it->second;
            
            if (time > max_time){
                result++;
                max_time = time;
            }
            
        }
        
        
        return result;
    }

};