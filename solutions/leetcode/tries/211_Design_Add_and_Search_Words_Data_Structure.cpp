#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

struct TrieNode {

    bool is_word;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);

    TrieNode() {
        is_word = false;
    }

};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;

        int i = 0;

        while (i < word.size()){
            int index = word[i] - 'a';
            if (current->children[index] == nullptr){
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
            i++;
        }
        current->is_word = true;

    }
    
    bool search(string word) {
        return traverse(root, word, 0);
    }
private:
    TrieNode* root;

    bool traverse(TrieNode* node, string& word, int index){
        if (node == nullptr){
            return false;
        }

        if (index == word.size()){
            return node->is_word;
        }

        if (word[index] != '.'){
            return traverse(node->children[word[index] - 'a'], word, index + 1);
        }

        for (int j = 0; j < 26; j++){
            if (traverse(node->children[j], word, index + 1)){
                return true;
            }
        }

        return false;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */