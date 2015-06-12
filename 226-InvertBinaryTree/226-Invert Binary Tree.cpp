/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //non-recursive version
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* T = root;
        if(T == nullptr) return nullptr;
        unvist.push(T);
        while(!unvist.empty()){
            T = unvist.top();
            unvist.pop();
            swapNode(T);
            if(T->left != nullptr) unvist.push(T->left);
            if(T->right != nullptr) unvist.push(T->right);
        }
        return root;
    }
    
private:
    void swapNode(TreeNode* node){
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    stack<TreeNode*> unvist;
};
