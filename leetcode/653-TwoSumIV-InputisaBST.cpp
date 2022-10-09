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
class BSTIterator {
    private:
    stack<TreeNode*> st;
    bool right = false;
    void push(TreeNode* root){
        while (root){
            st.push(root);
            root = right ? root->right: root->left;
        }
    }
    public:
    BSTIterator(TreeNode* root, bool right=false) : right(right){
        push(root);
    }
    int next(){
        TreeNode* tmp = st.top();
        st.pop();
        push(!right? tmp->right: tmp->left);
        return tmp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator leftIt(root), rightIt(root, true);
        int left = leftIt.next(), right = rightIt.next();
        while (left < right){
            if (left + right == k){
                return true;
            }
            else if (left + right < k){
                left = leftIt.next();
            }
            else {
                right = rightIt.next();
            }
        }
        return false;
    }
};