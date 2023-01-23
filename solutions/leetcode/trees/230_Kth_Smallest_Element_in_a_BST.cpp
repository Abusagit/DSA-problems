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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        int node_order = 0;
        
        return inorder(root, node_order);
    }
private:
    int k;
    int inorder(TreeNode* node, int& node_order){
        if (node == nullptr){
            return -1;
        }
        
        int left_inorder = inorder(node->left, node_order);
        node_order++;
        
        if (node_order > k){
            return left_inorder;
        }
        
        if (node_order == k){
            return node->val;
        }
        
        return inorder(node->right, node_order);
    }
};