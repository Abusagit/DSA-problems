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
    int maxDepth(TreeNode* root) {
        return traverseTree(root, 0);
    }
private:
    
    int traverseTree(TreeNode* node, int current_depth){
        
        if (node == nullptr){
            return current_depth;
        }

        int left_depth = traverseTree(node->left, current_depth + 1), right_depth = traverseTree(node->right, current_depth + 1);

        int max_depth = max(left_depth, right_depth);

        return max_depth;
    }
};