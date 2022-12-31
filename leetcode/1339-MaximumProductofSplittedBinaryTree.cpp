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
    long long totalSum = 0, result = 0;
public:
    int subtreeSum(TreeNode* root){
        if (!root){
            return 0;
        }
        long long currSum = subtreeSum(root->right) + subtreeSum(root->left) + root->val;
        result = max(result, (totalSum - currSum) * currSum);
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = subtreeSum(root);
        subtreeSum(root);
        return result % 1000000007;
    }
};