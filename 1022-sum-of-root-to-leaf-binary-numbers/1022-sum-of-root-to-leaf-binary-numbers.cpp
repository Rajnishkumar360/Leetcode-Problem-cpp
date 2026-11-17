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
    int binaryDecimal(string s){
        int decValue = 0;
        for(char c:s){
            decValue = decValue*2+(c-'0');
        }
        return decValue;
    }
    int helper(TreeNode*root,string path){
        if(root == NULL) return 0;
        path += to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            return binaryDecimal(path);
        }
        return helper(root->left,path) + helper(root->right,path);
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root,"");
    }
};