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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }

        int depth = 0;

        return treeDepth(root, depth);

    }
private:
    bool treeDepth(TreeNode* node, int& current_depth){
        if (node == nullptr){
            current_depth = -1;
            return true;
        }

        int left_depth = 0, right_depth = 0;

        // also updates depths:
        bool is_balanced_left = treeDepth(node->left, left_depth);
        bool is_balanced_right = treeDepth(node->right, right_depth);

        if (!(is_balanced_left && is_balanced_right) || abs(left_depth - right_depth) > 1){
            return false;
        }

    
        current_depth = 1 + max(left_depth, right_depth);
        return true;

    }
};