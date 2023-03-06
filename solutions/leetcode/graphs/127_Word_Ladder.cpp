class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();

        create_graph(wordList, beginWord);

        // for (auto s: adjacent){
        //     cout << s.first << ": ";

        //     for (auto x: s.second){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        if (adjacent.find(endWord) == adjacent.end()){
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 0});


        int words_sequence = 0;

        while (!q.empty()){
            auto top = q.front();
            q.pop();

            if (top.first == endWord){
                words_sequence = top.second + 1;
                break;
            }

            bfs(top.first, top.second, q);
        }

        return words_sequence;


    }
private:
    int n;

    unordered_map<string, vector<string>> adjacent;
    unordered_set<string> visited;


    void bfs(string s, int time, queue<pair<string, int>>& q){
        if (visited.find(s) != visited.end()){
            return;
        }

        visited.insert(s);

        for (string adj_s: adjacent[s]){
            q.push({adj_s, time + 1});
        }
    }

    bool are_adjacent(string s1, string s2){
        int different = 0;
        for (int i = 0; i < s1.size(); i++){
            different += s1[i] != s2[i];
        }
        return different == 1;
    }

    void calculate_differences(string s, int index, vector<string>& wordList){
        for (int j = index + 1; j < n; j++){
            string s_j = wordList[j];

            if (are_adjacent(s, s_j)){
                adjacent[s].push_back(s_j);
                adjacent[s_j].push_back(s);
            }
        }
    }
    void create_graph(vector<string>& wordList, string& startWord){
        // sort(wordList.begin(), wordList.end());

        for (int i = 0; i < n; i++){
            calculate_differences(wordList[i], i, wordList);
        }

        if (adjacent.find(startWord) == adjacent.end()){
            calculate_differences(startWord, -1, wordList);
        }
    }
};