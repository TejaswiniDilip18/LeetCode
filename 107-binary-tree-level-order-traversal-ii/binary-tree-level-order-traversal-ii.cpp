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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result, revResult;
        if(!root) return result;

        std::queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currentLevelNodes;

            for(int i =0; i<levelSize; i++){
                TreeNode* currentNode = q.front();
                q.pop();

                currentLevelNodes.push_back(currentNode->val);

                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }
            result.push_back(currentLevelNodes);
        }

        // for(auto it = result.rbegin(); it != result.rend(); it++){
        //     revResult.push_back(*it);
        // }
        reverse(result.begin(), result.end());
        return result;
    }
};