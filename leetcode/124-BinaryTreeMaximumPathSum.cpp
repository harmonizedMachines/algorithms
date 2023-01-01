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
private:
    int maxSum = INT_MIN;
    
    int maxSubtree(TreeNode* root){
        if (!root){
            return 0;
        }
        int l = max(0, maxSubtree(root->left));
        int r = max(0, maxSubtree(root->right));
        maxSum = max(maxSum, l + r + root->val);
        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSubtree(root);
        return maxSum;
    }
};