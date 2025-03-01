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
    TreeNode* constructTree(vector<int>& preorder, map<int,int>& mp, int preStart, int preEnd, int inStart, int inEnd){

        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int idx = mp[root->val];
        int leftSize = idx - inStart;
        
        root->left = constructTree(preorder, mp, preStart+1, preStart+leftSize, inStart, idx-1);
        root->right = constructTree(preorder, mp, preStart+leftSize+1, preEnd, idx+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;

        // add all nodes of inorder to the map
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return constructTree(preorder, mp, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};