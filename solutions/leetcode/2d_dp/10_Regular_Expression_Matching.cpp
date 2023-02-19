class Solution {
public:
    bool isMatch(string s, string p) {
        return regex_match(s, p, 0, 0);
    }
private:
    map<pair<int, int>, bool> d;

    bool regex_match(string& s, string& p, int i, int j){
        if (d.find({i, j}) != d.end()){
            return d[{i, j}];
        }

        if (i >= s.size() && j >= p.size()){
            return true;
        }

        if (j >= p.size()){
            return false;
        }

        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

        // check if next element in pattern is *

        if ((j + 1 < p.size()) && (p[j + 1] == '*')){
                    //  don`t use symbol with star         use star and check next symbol in s and remain with star
            d[{i, j}] = regex_match(s, p, i, j + 2) || (match && regex_match(s, p, i + 1, j));
            return d[{i, j}];
        } 
        if (match){
            d[{i, j}] = regex_match(s, p, i + 1, j + 1);
            return d[{i, j}];
        } 
        
        d[{i, j}] = false;
        return d[{i, j}];
    }
};