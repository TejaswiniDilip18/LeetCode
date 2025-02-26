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
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(!root) return {};

//         vector<vector<pair<int,long>>> result;
//         queue<pair<TreeNode*, long>> q;

//         q.push({root, 0});

//         while(!q.empty()){
//             int level = q.size();
//             vector<pair<int,long>> midResult;

//             for(int i=0; i<level; i++){
//                 TreeNode* currNode = q.front().first;
//                 long idx = q.front().second;
//                 q.pop();

//                 int minIdx;
//                 if(i==0) minIdx = idx;
//                 idx -= minIdx;

//                 long leftIdx = (2*idx) + 1;
//                 long rightIdx = (2*idx) + 2;

//                 if(currNode->left) q.push({currNode->left, leftIdx});
//                 if(currNode->right) q.push({currNode->right, rightIdx});

//                 midResult.push_back({currNode->val, idx});
//             }
//             result.push_back(midResult);         
//         }

//         int width = INT_MIN;

//         for(auto vec: result){
//             if(vec.size()>1){
//                 int currWidth = vec[vec.size()-1].second - vec[0].second;
//                 width = max(width, currWidth);
//             }
//         }

//         return width==INT_MIN? 1: width+1;
//     }
// };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, long>> q;

        q.push({root, 0});

        int maxWidth = 0;

        while(!q.empty()){
            int level = q.size();
            vector<pair<int,long>> midResult;
            long first = 0, last = 0;
            long minIdx = q.front().second;

            for(int i=0; i<level; i++){
                TreeNode* currNode = q.front().first;
                long idx = q.front().second;
                q.pop();
                idx -= minIdx;

                if(i==0) first = idx;
                if(i==level-1) last = idx;

                long leftIdx = (2*idx);
                long rightIdx = (2*idx) + 1;

                if(currNode->left) q.push({currNode->left, leftIdx});
                if(currNode->right) q.push({currNode->right, rightIdx});
            }
            maxWidth = max(maxWidth, static_cast<int>(last-first+1));       
        }

        return maxWidth;
    }
};