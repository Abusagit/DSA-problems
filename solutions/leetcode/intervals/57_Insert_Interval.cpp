class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int i = 0, n = intervals.size();


        // keep pushing intervals which end earlier than newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        // keep modifying intervals which overlap and merge them
        while (i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.push_back(newInterval);

        // keep add intervals which start later than overlapping
        while (i < n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;


    }
};