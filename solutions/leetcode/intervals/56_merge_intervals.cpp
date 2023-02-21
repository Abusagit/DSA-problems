class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int i = 0;

        while (i < n){
            vector<int> new_interval = intervals[i];


            while ((i < n - 1) && (new_interval[1] >= intervals[i + 1][0])){
                new_interval[0] = min(new_interval[0], intervals[i + 1][0]);
                new_interval[1] = max(new_interval[1], intervals[i + 1][1]);
                i++;
            }

            result.push_back(new_interval);
            i++;
        }

        return result;
    }
};