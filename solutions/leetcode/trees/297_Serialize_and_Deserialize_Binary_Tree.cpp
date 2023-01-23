/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream output;
        encode(root, output);
        
        return output.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        
        return decode(input);
    }
private:
    void encode(TreeNode* root, ostringstream& out){
        if (root == nullptr){
            out << "N ";
            return;
        }
        
        out << root->val << ' ';
        
        encode(root->left, out);
        encode(root->right, out);
    }
    
    TreeNode* decode(istringstream& input){
        
        string val; input >> val;
        
        if (val == "N"){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        
        root->left = decode(input);
        root->right = decode(input);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));