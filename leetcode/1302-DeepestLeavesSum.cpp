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
    int h;
    int height(TreeNode* root){
        if (!root->right && !root->left){
            return 1;
        }
        return 1 + max(root->right ? height(root->right) : 0, 
                      root->left ? height(root->left) : 0);
    }
    
    int sumDeepest(TreeNode* root, int currheight){
        if (!root){
            return 0;
        }
        if (h - 1 == currheight){
            return root->val;
        }
        return sumDeepest(root->left, currheight+1) + sumDeepest(root->right, currheight+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        h = height(root);
        return sumDeepest(root, 0);
    }
};