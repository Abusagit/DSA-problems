// if s[i] = t[j], we can either increment both indices or increment only k > i to seek for another possiblt s[k] == t[j]
// if s[i] != t[j] we only can increment i because we have all j to be matched


class Solution {
public:
    int numDistinct(string s, string t) {

        return dfs(s, t, 0, 0);
    }
private:

    map<pair<int, int>, int> d;

    int dfs(string& s, string& t, int i, int j){
        if (j == t.size()){
            return 1;
        }

        if (i == s.size()){
            return 0;
        }

        if (d.find({i, j}) != d.end()){
            return d[{i, j}];
        }

        if (s[i] == t[j]){
            d[{i, j}] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
        } else {
            d[{i, j}] = dfs(s, t, i + 1, j);
        }

        return d[{i, j}];
    }

    
};