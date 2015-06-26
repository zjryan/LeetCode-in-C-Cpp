/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* T = root;
        if(T == nullptr) return true;
        if(T->left && T->right && T->left->val != T->right->val) return false;
        
        vector<int> leftTree;
        InorderTraversal(T->left, leftTree);
        vector<int> rightTree;
        InorderTraversal(T->right, rightTree);
        if(leftTree.size() != rightTree.size()) return false;
        else{
            int len = leftTree.size();
            for(int i = 0; i < len; i++)
                if(leftTree[i] != rightTree[len - 1 - i]) return false;
            return true;
        }
    }
private:
    void InorderTraversal(TreeNode* root, vector<int>& result){
        TreeNode* T = root;
        if(T == nullptr){
            result.push_back(0);
            return;
        }
        else if(T->left == nullptr && T->right == nullptr){
            result.push_back(T->val);
            return;
        }
        else{
            InorderTraversal(T->left, result);
            result.push_back(T->val);
            InorderTraversal(T->right, result);
        }
    }
};
