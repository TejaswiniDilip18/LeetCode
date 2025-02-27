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
    int maxDepth(TreeNode* root, int& diff) {
        if(!root) return 0;
        int leftHeight = maxDepth(root->left, diff);
        int rightHeight = maxDepth(root->right, diff);
        diff = max(diff, abs(leftHeight-rightHeight));
        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int diff = INT_MIN;
        maxDepth(root, diff);
        if(diff > 1) return false;
        else return true;
    }
};