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
    int checkDepth(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = checkDepth(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = checkDepth(root->right);
        if(rightHeight == -1) return -1;
        
        if(abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        // if(!root) return true;
        if(checkDepth(root) == -1) return false;
        else return true;
    }
};