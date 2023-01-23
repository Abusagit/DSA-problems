#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertNode(root);

        return root;
    }

    TreeNode* invertTreeQuick(TreeNode* root){
        if (root == nullptr){
            return nullptr;    
        }

        swap(root->left, root->right);
        invertTreeQuick(root->left);
        invertTreeQuick(root->right);
        return root;
    }

    TreeNode* invertTreeStack(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}

private:
    void invertNode(TreeNode* node){
        if ((node == nullptr) || (node->left == nullptr && node-> right == nullptr)){
            return;
        }

        invertNode(node->left);
        invertNode(node->right);

        TreeNode* left = node->left;
        node->left = node->right;
        node->right = left;


    }
};