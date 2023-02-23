class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> index_we_can_form;

        for (auto triplet: triplets){
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){ // filter triplets which cannot form target triplet at all
                continue;
            }
            // x <= x_t && y <= y_t && z <= z_t

            // triplet is candidate to form target triplet at least in on of positions

            // all triplets here have values at most as target`s values in according coordinates
            for (int j = 0; j < 3; j++){
                if (triplet[j] == target[j]){
                    index_we_can_form.insert(j);
                }
            }

        }


        return index_we_can_form.size() == 3;
    }
};