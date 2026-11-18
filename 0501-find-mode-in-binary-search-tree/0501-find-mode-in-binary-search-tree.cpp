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
    vector<int> findMode(TreeNode* root) {
        if (root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, int>mp;
        int maxCount = 0;
        while (q.size()!=0) {
            TreeNode* curr = q.front();
            q.pop();
            mp[curr->val]++;
            maxCount = max(maxCount, mp[curr->val]);
            if (curr->left!=NULL) q.push(curr->left);
            if (curr->right!=NULL) q.push(curr->right);
        }
        vector<int> freq;
        for (auto x : mp) {
            if (x.second == maxCount) {
               freq.push_back(x.first);
            }
        }
        return freq;
    }
};