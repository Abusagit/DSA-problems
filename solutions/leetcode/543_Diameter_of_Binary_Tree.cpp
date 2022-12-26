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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }

private:
    int dfs(TreeNode* node, int& depth){ // --> max diameter_of_subtree
        if (node == nullptr){
            return 0;
        }

        int left_depth = 0;
        int right_depth = 0;

        int left_diameter = dfs(node->left, left_depth), right_diameter = dfs(node->right, right_depth);

        depth = 1 + max(left_depth, right_depth);

        return max({left_diameter, right_diameter, left_depth + right_depth});
    }
};