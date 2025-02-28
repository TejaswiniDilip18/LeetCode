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

 /*
 // Solution for Binary Tree
class Solution {
public:
    void dfs(TreeNode*& root, int& k, priority_queue<int>& pq){
        if(!root) return;
        pq.push(root->val);
        if(pq.size() > k) pq.pop();
        dfs(root->left, k, pq);
        dfs(root->right, k, pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        dfs(root, k, pq);
        return pq.top();
    }
};
*/

// Better Solution for BST
class Solution {
public:
    void dfs(TreeNode*& root, int& k, int& smallest){
        if(!root) return;
        dfs(root->left, k, smallest);
        k--;
        if(k==0){
            smallest = root->val;
        }
        dfs(root->right, k, smallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int smallest = 0;
        dfs(root, k, smallest);
        return smallest;
    }
};