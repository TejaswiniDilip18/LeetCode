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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root, {0,0}});

        map<int, map<int, vector<int>>> mp;
        // mp[0][0].push_back(root->val);

        while(!q.empty()){
            int level = q.size();

            for(int i=0; i<level; i++){
                TreeNode* curr = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();

                mp[col][row].push_back(curr->val);

                if(curr->left){
                    // mp[col-1][row+1].push_back(curr->left->val);
                    q.push({curr->left, {row+1,col-1}});
                }
                if(curr->right){
                    // mp[col+1][row+1].push_back(curr->right->val);
                    q.push({curr->right, {row+1,col+1}});
                }
            }
        }

        // store order in vector
        for(const auto& cols: mp){
            auto inner_mp = cols.second;
            vector<int> temp;
            for(const auto& rows: inner_mp){
                vector<int> inner_vec = rows.second;
                sort(inner_vec.begin(), inner_vec.end());
                temp.insert(temp.end(), inner_vec.begin(), inner_vec.end());              
            }
            result.push_back(temp);
        }

        return result;
    }
};