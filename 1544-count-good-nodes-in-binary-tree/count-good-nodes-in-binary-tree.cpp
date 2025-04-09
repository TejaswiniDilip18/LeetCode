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
    void dfs(TreeNode* root, int& goodNodeCount, int currMax){
        if(!root) return;
        
        if(root->val >= currMax){
            goodNodeCount++;
            currMax = root->val;
        }
        dfs(root->left, goodNodeCount, currMax);        
        dfs(root->right, goodNodeCount, currMax);

        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int goodNodeCount = 0, currMax = root->val;
        dfs(root, goodNodeCount, currMax);
        return goodNodeCount;
    }
};