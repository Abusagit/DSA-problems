// implement prefix tree for queries

// walk through board and if there exists such path that comprises word from queries, add this word
// prefix tree lets searching faster, as we can continue searching for a word after its substring matched


#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool is_word;
    
    TrieNode() {
        is_word = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        root = new TrieNode();

        for (auto word: words){
            insert(word);
        }

        m = board.size(), n = board.front().size();

        vector<string> result;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                search(board, i, j, root, "", result);
            }
        }

        return result;
        
    }
private:
    TrieNode* root;
    int m, n;

    void search(vector<vector<char> >& board, int i, int j, TrieNode* node, string word, vector<string>& result){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '@'){
            return;
        }

        char c = board[i][j];

        node = node->children[c - 'a'];


        // node is TrieNode with letter c 
        if (node == nullptr){
            return;
        }

        word += board[i][j];

        if (node->is_word){
            result.push_back(word);
            node->is_word = false;
        }

        board[i][j] = '@';

        search(board, i + 1, j, node, word, result);
        search(board, i - 1, j, node, word, result);
        search(board, i, j + 1, node, word, result);
        search(board, i, j - 1, node, word, result);


        board[i][j] = c;

    }   

    void insert(string word){
        TrieNode* node = root;

        // int index = 0;

        for (int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';

            if (node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->is_word = true;

    }
};