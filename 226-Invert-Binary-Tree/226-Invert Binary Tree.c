/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* T = root;
    if(T == NULL) return NULL;
    struct TreeNode* tmp = T->right;
    T->right = T->left;
    T->left = tmp;
    invertTree(T->left);
    invertTree(T->right);
    return T;
}
