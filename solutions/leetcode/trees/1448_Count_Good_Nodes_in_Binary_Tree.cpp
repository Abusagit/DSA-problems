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
    int goodNodes(TreeNode* root) {
        dfs(root, root->val - 1);
        return good;
    }
private:
    int good = 0;
    void dfs(TreeNode* node, int max_val_on_path){
        if (node == nullptr){
            return;
        }
        
        if (node->val >= max_val_on_path){
            good++;
            max_val_on_path = node->val;
        }
        dfs(node->right, max_val_on_path);
        dfs(node->left, max_val_on_path);

    }
};