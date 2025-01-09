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
    void dfs(TreeNode* root, string currentPath, vector<string>& result){
        if(!root) return;

        currentPath +=to_string(root->val);

        if(!root->left && !root->right){
            result.push_back(currentPath);
        }
        else{
            currentPath += "->";
            if(root->left) dfs(root->left, currentPath, result);
            if(root->right) dfs(root->right, currentPath, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> result;
        if(!root) return result;

        dfs(root, "",result);

        return result;
    }
};