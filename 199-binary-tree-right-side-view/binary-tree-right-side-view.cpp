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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        vector<int> result;
        
        map<int, int> mp;
        queue<std::pair<TreeNode*, int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            int level = q.size();
            
            for(int i=0; i<level; i++){
                TreeNode* curr = q.front().first;
                int row = q.front().second;
                q.pop();
                
                // if(mp.find(col) == mp.end()){}
                mp[row] = curr->val;
                
                if(curr->left) q.push({curr->left, row+1});
                if(curr->right) q.push({curr->right, row+1});
            }
        }
        
        for(auto val: mp){
            result.push_back(val.second);
        }
        return result;
    }
};