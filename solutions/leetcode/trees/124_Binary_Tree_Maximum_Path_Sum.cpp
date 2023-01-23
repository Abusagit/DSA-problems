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
    int maxPathSum(TreeNode* root) {
        int max_sum = root->val;
        
        dfs(root, max_sum);
        
        return max_sum;
    }
private:
    int dfs(TreeNode* node, int& max_sum){ // returns max sum without splitting
        if (node == nullptr){
            return 0;
        }
        
        int max_left_sum_wo_split = max(dfs(node->left, max_sum), 0);
        int max_right_sum_wo_split = max(dfs(node->right, max_sum), 0);
        
        max_sum = max(max_sum, node->val + max_left_sum_wo_split + max_right_sum_wo_split); //contains max with splitting and without
        
        return node->val + max(max_left_sum_wo_split, max_right_sum_wo_split);
    }
};