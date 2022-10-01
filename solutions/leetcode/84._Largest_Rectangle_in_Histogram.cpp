#include <vector>
#include <utility>
#include <algorithm>
#include <stack>


class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        
        
        std::stack<std::pair<int,int>> index_height; // strictly increasing stack by the first argument
        
        int max_area = 0;
        int start_index, height, area;

        index_height.push({0, heights[0]});

        for (int i=1; i < heights.size(); i++){

            if (heights[i] < index_height.top().second){
                int new_start;
                while (!(index_height.empty()) && (heights[i] < index_height.top().second))
                {
                    start_index = index_height.top().first;
                    height = index_height.top().second;
                    area = height * (i - start_index);
                    max_area = std::max({max_area, area});

                    index_height.pop();

                    new_start = start_index;
                }
                
                index_height.push({new_start, heights[i]});
                
            } else if (heights[i] > index_height.top().second){
                index_height.push({i, heights[i]});
                }

        }
        
        int n = heights.size();
        while (!(index_height.empty()))
        {
            start_index = index_height.top().first;
            height = index_height.top().second;
            area = height * (n - start_index);

            index_height.pop();

            max_area = std::max({max_area, area});
        }

        return max_area;

    }

};