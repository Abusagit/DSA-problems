class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<vector<int>> intervals_sorted = construct_intervals(s);
        vector<int> result;

        int i = 0;
        int n = intervals_sorted.size();

        while (i < n){
            vector<int> current_interval = intervals_sorted[i];

            while (i < n - 1 && current_interval[1] >= intervals_sorted[i + 1][0]){
                current_interval[1] = max(current_interval[1], intervals_sorted[i + 1][1]);
                i++;
            }
            result.push_back(current_interval[1] - current_interval[0] + 1);

            i++;

        }

        return result;
    }
private:

    vector<vector<int>> construct_intervals(string& s){

        vector<vector<int>> first_last_occurence(26, vector<int>(2, -1));

        for (int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';

            if (first_last_occurence[index][0] == -1){
                first_last_occurence[index][0] = i;
                first_last_occurence[index][1] = i;
            } else {
                first_last_occurence[index][1] = i;
            }
        }

        vector<vector<int>> intervals_unsorted;

        for (auto x: first_last_occurence){
            if (x[0] != -1){
                intervals_unsorted.push_back(x);
            }
        }

        sort(intervals_unsorted.begin(), intervals_unsorted.end(), 
                            [](const std::vector<int>& a, const std::vector<int>& b) {
                                return a[0] < b[0];}); // custom less function

        for (auto x: intervals_unsorted){
            cout << x[0] << " " << x[1] << '\n';
        }

        return intervals_unsorted;
    }
};


// faster solution:
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // {char -> last index in s}
        vector<int> lastIndex(26);
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        int size = 0;
        int end = 0;
        
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            size++;
            // constantly checking for further indices if possible
            end = max(end, lastIndex[s[i] - 'a']);
            if (i == end) {
                result.push_back(size);
                size = 0;
            }
        }
        
        return result;
    }
};