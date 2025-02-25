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
    void dfs(TreeNode* root, vector<int>& result){
        // <left><root><right>
        if(root->left) dfs(root->left, result);
        result.push_back(root->val);
        if(root->right) dfs(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        dfs(root, result);
        return result;
    }
};