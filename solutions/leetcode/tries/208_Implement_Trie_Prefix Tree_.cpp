class TrieNode {
public:
    bool is_word_end;

    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        int index = 0;
        while (index < word.size()){
            int child_node_index = word[index] - 'a';

            if (node->children[child_node_index] == nullptr){
                node->children[child_node_index] = new TrieNode();
            }

            node = node->children[child_node_index];
            index++;
        }
        node->is_word_end = true;

    }
    
    bool search(string word) {
        return traverse(word, false);
    }
    
    bool startsWith(string prefix) {
        return traverse(prefix, true);
    }
private:
    TrieNode* root;

    bool traverse(string& s, bool startswith_mode){
        TrieNode* node = root;
        int index = 0;

        while (index < s.size()){
            int child_node_index = s[index] - 'a';

            if (node->children[child_node_index] == nullptr){
                return false;
            }

            node = node->children[child_node_index];
            index++;
        }

        return (startswith_mode) ? true : node->is_word_end;
    }


};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */