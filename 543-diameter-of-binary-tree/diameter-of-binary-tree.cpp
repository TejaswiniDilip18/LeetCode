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
    int findDiameter(TreeNode* root, int& diameter){
        if(!root) return 0;

        int l = findDiameter(root->left,diameter);
        int r = findDiameter(root->right, diameter);
        diameter = max(diameter, l+r);

        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;

        findDiameter(root, diameter);

        return diameter;
    }
};