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
    int helper(TreeNode* root){
        if(root==NULL) return  0;
        return root->val +  helper(root->left) + helper(root->right);
    }
    bool checkTree(TreeNode* root) {
        if(root==NULL) return false;
        int temp = root->val;
        int sum = helper(root->left) + helper(root->right);
        if(sum ==temp){
            return true;
        }
        return false;
    }
};