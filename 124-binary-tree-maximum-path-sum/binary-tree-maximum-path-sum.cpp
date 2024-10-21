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
    int maxSum = INT_MIN;
    int postOrderSum(TreeNode* root){
        if(!root) return 0;

        int rightSum = max(postOrderSum(root->right), 0);
        int leftSum = max(postOrderSum(root->left), 0);

        maxSum = max(maxSum, (rightSum+leftSum+root->val));     

        return root->val+max(rightSum, leftSum); 
    }
    int maxPathSum(TreeNode* root) {
        postOrderSum(root);
        return maxSum;                
    }
};