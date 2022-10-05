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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* res = new TreeNode(val, root, NULL);
            return res;
        }
        if (depth == 2){
            TreeNode *left = new TreeNode(val, root->left, NULL);
            TreeNode *right = new TreeNode(val, NULL, root->right);
            root->left = left;
            root->right = right;
            return root;
        }
        if (root->right){
            root->right = addOneRow(root->right, val, depth - 1);
        }
        if (root->left){
            root->left = addOneRow(root->left, val, depth - 1);
        }
        return root;
    }
};