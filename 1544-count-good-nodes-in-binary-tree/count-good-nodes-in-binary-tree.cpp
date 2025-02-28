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
    void dfs(TreeNode*& root, int& count, int X){
        if(!root) return;
        if(root->val >= X){
            X = root->val;
            count++;
        }
        dfs(root->left, count, X);
        dfs(root->right, count, X);
    }

    int goodNodes(TreeNode* root) {
        int X = root->val;
        int count = 0;
        dfs(root, count, X);
        return count;
    }
};