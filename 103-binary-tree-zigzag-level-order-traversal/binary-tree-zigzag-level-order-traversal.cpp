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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;

        if(!root) return {};

        q.push(root);
        int level = 0;

        while(!q.empty()){
            level++;
            vector<int> temp;
            int k = q.size();
            
            for(int i=0; i<k; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                temp.push_back(curr->val);
            }
            if(level%2==0){
                reverse(temp.begin(), temp.end());
                
            }
            result.push_back(temp);
        }
        return result;
    }
};