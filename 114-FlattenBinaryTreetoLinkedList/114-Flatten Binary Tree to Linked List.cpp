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
    void flatten(TreeNode* root) {
        TreeNode* T = root;
        if(T == nullptr) return;
        unvist.push(T);
        TreeNode* PreT = nullptr;
        while(!unvist.empty()){
            T = unvist.top();
            unvist.pop();
            if(PreT != nullptr){
                PreT->right = T;
                PreT->left = nullptr;
            }
            if(T->right != nullptr) unvist.push(T->right);
            if(T->left != nullptr) unvist.push(T->left);
            PreT = T;
        }
    }
private:
    stack<TreeNode*> unvist;
};
