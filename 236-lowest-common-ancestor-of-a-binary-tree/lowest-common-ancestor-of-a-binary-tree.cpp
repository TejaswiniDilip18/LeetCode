/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* ancestor){
    //     // if it is a leaf node, check if it's p or q 
    //     // if yes, return the node else return null

    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if( left != nullptr &&  right != nullptr){
            return root;
        }
        else if(left != nullptr) return left;
        else return right;
    }
};