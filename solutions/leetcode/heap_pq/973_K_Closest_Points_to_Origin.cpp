class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct {
            bool operator() (vector<int> l, vector<int> r) const { return l[0] * l[0] + l[1] * l[1] > r[0] * r[0] + r[1] * r[1];}
        } customLess;
        
        std::priority_queue minq(points.begin(), points.end(), customLess);
        
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++){
            result.push_back(minq.top());
            minq.pop();
        }
        
        return result;
        
    }
};