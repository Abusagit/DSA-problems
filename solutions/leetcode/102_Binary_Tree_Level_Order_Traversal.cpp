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
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);

        vector<vector<int>> tree_levels_ordered;
        for (int i = 0; i < tree_levels.size(); i++){
            tree_levels_ordered.push_back(tree_levels[i]);
        }

        return tree_levels_ordered;
    }
private:
    unordered_map<int, vector<int>> tree_levels;

    void dfs(TreeNode* node, int depth){

        if (node == nullptr){
            return;
        }

        tree_levels[depth].push_back(node->val);
//        cout << depth << " " << tree_levels[depth].size() <<"\n";

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};