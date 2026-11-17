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
    int helper(TreeNode* root,int currValue){
            if(root==NULL) return 0;
            currValue = (currValue*2) | root->val;
            if(root->left==NULL && root->right==NULL){
                return currValue;
            }
            return helper(root->left,currValue) + helper(root->right,currValue);
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root,0);
    }
};