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
        vector<vector<int>> result;
        if(!root) return result;

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<int> currLevel;
            for(int i=0; i<level; i++){
                TreeNode* currentNode = q.front();
                q.pop();

                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);

                currLevel.push_back(currentNode->val);
            }
            result.push_back(currLevel);
        }

        return result;
    }
};