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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            split_inorder_index[inorder[i]] = i;
        }
        
        preorder_index = 0;
        return build(preorder, 0, preorder.size() - 1);
    }
private:
    unordered_map<int, int> split_inorder_index;
    int preorder_index;
    
    TreeNode* build(vector<int>& preorder, int left, int right){
        
        if (left > right){
            return nullptr;
        }
        
        int root_val = preorder[preorder_index++];
        
        int split_index = split_inorder_index[root_val];
        
        TreeNode* root = new TreeNode(root_val);
        
        root->left = build(preorder, left, split_index - 1);
        root->right = build(preorder, split_index + 1, right);
        
        return root;
    }
    
};