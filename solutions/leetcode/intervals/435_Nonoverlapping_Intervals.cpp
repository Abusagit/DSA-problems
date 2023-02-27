class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });




        int removed = 0;
        vector<int>& prev = intervals[0];

        for (auto interval = intervals.begin() + 1; interval != intervals.end(); interval++){

            if (prev[1] > (*interval)[0]){
                removed++;
                // cout << prev[0] << '-' << prev[1] << ' ' << (*interval)[0]<< '-' << (*interval)[1] << '\n';
                if (prev[1] >= (*interval)[1]){
                    prev = *interval;
                }
            } else {
                prev = *interval;
            }
        }

        return removed;
    }
};