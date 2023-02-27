class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;

        // sort intrrvals by length and end
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // sort queries in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());
        // sort intervals by start
        sort(intervals.begin(), intervals.end());
        unordered_map<int, int> map;

        int i = 0;
        for (int query: sortedQueries){

            // intervals in pq are sorted by length of interval in ascending order

            // get intervals which start earlier than query
            while (i < intervals.size() && intervals[i][0] <= query){
                int right = intervals[i][1];
                int left = intervals[i][0];
                pq.push({right - left + 1, right});
                i++;
            }

            // filter intervals which end earlier than query ==> earlier than any other larger query==> can throw out
            while (!pq.empty() && pq.top().second < query){
                pq.pop();
            }

            // if pq is empty -  no intervals contain query
            // if pq contains something - get top element as it has smallest length
            if (!pq.empty()){
                map[query] = pq.top().first;
            } else {
                map[query] = -1;
            }
        }


        for (int i = 0; i < queries.size(); i++){
            sortedQueries[i] = map[queries[i]];
        }

        return sortedQueries;


    }
};