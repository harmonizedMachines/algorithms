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
    int count = 0;
    unordered_set<int> elements = {};
    
    int pseudoPalindromicPaths (TreeNode* root) {
        traverse(root);
        return count;
    }
    
    void flip(TreeNode* root){
        if (!elements.count(root->val)){
            elements.insert(root->val);
        } else {
            elements.erase(root->val);
        }
    }
    
    void traverse(TreeNode* root){
        flip(root);
        if (!root->right && !root->left){
            if (elements.size() <= 1){
                count++;
            }
        }
        if (root->right){
            traverse(root->right);
        }
        if (root->left){
            traverse(root->left);
        }
        flip(root);
    }
};