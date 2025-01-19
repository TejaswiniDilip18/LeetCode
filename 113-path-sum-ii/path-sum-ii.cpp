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
    void getSum(TreeNode* root, int& targetSum, int sum, vector<int>& temp, vector<vector<int>>& result){
        
        if(!root) return;

        temp.push_back(root->val);
        sum += root->val;

        if(!root->left && !root->right){
            if(sum == targetSum){
                result.push_back(temp);
            }
        }
        
        getSum(root->left, targetSum, sum, temp, result);
        getSum(root->right, targetSum, sum, temp, result);

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>  result;
        vector<int> temp;
        int sum=0;
        getSum(root, targetSum, sum, temp, result);

        return result;
    }
};