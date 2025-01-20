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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<int> midResult;

            for(int i=0; i<level; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);

                midResult.push_back(currNode->val);
            }
            result.push_back(midResult);         
            
        }

        return result;
    }
};