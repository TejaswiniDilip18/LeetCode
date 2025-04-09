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
        currMax = max(currMax, root->val);
        dfs(root->left, goodNodeCount, currMax);
        if(root->val >= currMax) goodNodeCount++;
        dfs(root->right, goodNodeCount, currMax);

        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int goodNodeCount = 0, currMax = INT_MIN;
        dfs(root, goodNodeCount, currMax);
        return goodNodeCount;
    }
};