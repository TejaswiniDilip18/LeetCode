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
    int startIdx = 0;
    TreeNode* constructTree(vector<int>& preorder, map<int,int>& mp, int preStart, int preEnd){
        if(preStart > preEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[startIdx++]);

        int idx = mp[root->val];
        
        root->left = constructTree(preorder, mp, preStart, idx-1);
        root->right = constructTree(preorder, mp, idx+1, preEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;

        // add all nodes of inorder to the map
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return constructTree(preorder, mp, 0, inorder.size()-1);
    }
};