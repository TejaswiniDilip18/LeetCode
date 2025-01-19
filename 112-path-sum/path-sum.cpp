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
    bool dfs(TreeNode* root, int targetSum, int sum){
        if(!root) return false;

        sum += root->val;

        if(!root->left && !root->right){
            if(targetSum == sum) return true;
        }
        
        return (dfs(root->left, targetSum, sum) || dfs(root->right, targetSum, sum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return dfs(root, targetSum, sum);
    }
};