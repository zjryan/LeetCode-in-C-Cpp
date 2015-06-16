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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = 1;
        int rh = 1;
        TreeNode* T = root;
        while(T->left != nullptr){
            lh++;
            T = T->left;
        }
        T = root;
        while(T->right != nullptr){
            rh++;
            T = T->right;
        }
        if(lh == rh)
            return (1 << lh) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
