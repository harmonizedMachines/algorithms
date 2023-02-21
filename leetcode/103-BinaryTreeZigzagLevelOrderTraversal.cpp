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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int idx){
        if (!root){
            return;
        }
        helper(root->left, idx + 1);
        while (ans.size() <= idx){
            ans.push_back({});
        }
        ans[idx].push_back(root->val);
        helper(root->right, idx + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        helper(root, 0);
        for (int i = 0; i < ans.size(); ++i){
            if (i % 2){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};