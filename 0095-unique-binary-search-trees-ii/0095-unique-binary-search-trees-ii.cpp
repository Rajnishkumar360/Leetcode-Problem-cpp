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
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            result.push_back(root);
            return result;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_bsts = solve(start, i - 1);
            vector<TreeNode*> right_bsts = solve(i + 1, end);
                for (TreeNode* leftroot : left_bsts) {
                for (TreeNode* rightroot : right_bsts) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftroot;
                    root->right = rightroot;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};