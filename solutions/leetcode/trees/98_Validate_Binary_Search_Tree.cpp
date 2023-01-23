/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev_node = nullptr;
        
        return inorder(root, prev_node);
        
        
    }
private:
    bool inorder(TreeNode* node, TreeNode*& prev_node){
        
        if (node == nullptr){
            return true;
        }
        
        if (!inorder(node->left, prev_node)){
            return false; //inorder of left subtree first
        };
        
        
        // check whether next element is greater than previous
        if (prev_node!= nullptr && prev_node->val >= node->val){ // from smallest to largest
            return false;
        }
        
        // now current element is previous
        prev_node = node;
        
        // check inorder of right subtree
        if (!inorder(node->right, prev_node)){
            return false;
        }
        
        // if we are here then right and left subtrees are valid
        return true;
        
        
    }
};