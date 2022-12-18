class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int string_size = s.size();

        vector<bool> d(s.size() + 1, false);

        d[0] = true;
        // d[k] = can we segment our first k letters of s onto words from wordDict?

        for (int i = 0; i < string_size; i++){
            for (auto w: wordDict){
                if (i + w.size() <= string_size && s.substr(i, w.size()) == w && d[i + w.size()] == false){
                    d[i + w.size()] = d[i];
                }

            }
        }


        return d[string_size];
    }
};