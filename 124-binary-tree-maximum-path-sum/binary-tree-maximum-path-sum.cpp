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

    int findPathSum(TreeNode* root, int& sum){
        if(!root) return 0;

        int leftSum = max(0, findPathSum(root->left, sum));
        int rightSum = max(0, findPathSum(root->right, sum));
        sum = max(sum, leftSum+rightSum+root->val);

        return max(leftSum, rightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        findPathSum(root, sum);
        return sum;
    }
};