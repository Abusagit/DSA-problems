class Solution {
public:
    int countSubstrings(string s) {
        int palindrom_count = 0;

        for (int i = 0; i < s.size(); i++){
            is_palindrom(s, i, i, palindrom_count);
            is_palindrom(s, i, i + 1, palindrom_count);
        }

        return palindrom_count;
    }

private:
    void is_palindrom(string& s, int i, int j, int& palindrom_count){

        while (i >= 0 && j < s.size() && s[i] == s[j]){
            palindrom_count++;
            i -= 1;
            j += 1;
        }
    }
};