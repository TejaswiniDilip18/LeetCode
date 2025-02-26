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
    void dfs(TreeNode* root, vector<string>& result, string temp){
        if(!root) return;
        temp += to_string(root->val);
        if(!root->left && !root->right) result.push_back(temp);
        if(root->left || root->right){
            temp += "->";
        }
        if(root->left) dfs(root->left, result, temp);
        if(root->right) dfs(root->right, result, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, result, "");
        return result;
    }
};