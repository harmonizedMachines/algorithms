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
    vector<int> leaf1, leaf2;

    void addLeaves(TreeNode* root, vector<int>* leaf){
        if (!root){
            return;
        }
        addLeaves(root->right, leaf);
        if (!root->right && !root->left){
            leaf->push_back(root->val);
        }
        addLeaves(root->left, leaf);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        addLeaves(root1, &leaf1);
        addLeaves(root2, &leaf2);
        return leaf1 == leaf2;
    }
};