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
    int getPathSum(TreeNode* root, int& maxSum){
        if(!root) return 0;

        int rightSum = max(0, getPathSum(root->right, maxSum));
        int leftSum = max(0, getPathSum(root->left, maxSum));

        maxSum = max(maxSum, (root->val + leftSum + rightSum)); 

        return (root->val + max(rightSum, leftSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getPathSum(root, maxSum);
        return maxSum;
    }
};