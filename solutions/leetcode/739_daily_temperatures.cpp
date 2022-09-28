#include <vector>
#include <stack>


class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        
        std::stack<int> values;
        std::stack<int> indices;
        std::vector<int> result(temperatures.size());
        
        values.push(temperatures[0]);
        indices.push(0);
        
        for (int i=1; i < temperatures.size(); i++){
            while (!(values.empty()) && (temperatures[i] > values.top())){
                int stack_top_index = indices.top();
                result[stack_top_index] = i - stack_top_index;
                
                values.pop();
                indices.pop();
            }
            
            values.push(temperatures[i]);
            indices.push(i);
            
        }
        
        while (!(indices.empty())){
            result[indices.top()] = 0;
            indices.pop();
        }
        
        
        return result;

    }
    
        
};