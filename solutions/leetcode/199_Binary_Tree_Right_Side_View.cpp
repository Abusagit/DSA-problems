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
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return right_side_values;
    }
private:
    vector<int> right_side_values;
    
    void dfs(TreeNode* node, int depth){
        if (node == nullptr){
            return;
            }
        if (depth > right_side_values.size()){
            right_side_values.push_back(node->val);
            }
        
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
        }
};