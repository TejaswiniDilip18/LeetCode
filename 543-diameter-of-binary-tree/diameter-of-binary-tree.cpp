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
    int maxD = INT_MIN;
    int findMaxD(TreeNode* root){
        if(!root) return 0;
        
        int leftLen = findMaxD(root->left);
        int rightLen = findMaxD(root->right);

        maxD = max(maxD, leftLen + rightLen);

        return 1 + max(leftLen, rightLen);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        findMaxD(root);
        return maxD;
    }
};