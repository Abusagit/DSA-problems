class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);

        return result;
    }
private:
    vector<vector<string>> result;
    vector<string> current;

    void dfs(string& s, int start_index){
        if (start_index == s.size()){
            result.push_back(current); // every substring is a valid palindrom
        }

        for (int i = start_index; i < s.size(); i++){

            if (isPalindromSubstring(s, start_index, i)){ // s[start_index : i]
                string substring = s.substr(start_index, i - start_index + 1);
                current.push_back(substring);
                dfs(s, i + 1);
                current.pop_back();
            }
        }
    }

    bool isPalindromSubstring(string s, int left, int right){
        while (left < right){
            if (s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};