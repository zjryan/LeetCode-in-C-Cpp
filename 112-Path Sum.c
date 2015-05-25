/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    struct TreeNode* T = root;
    bool result;
    if(T == NULL) return 0;
    if(T->val == sum && T->right == NULL && T->left == NULL) return 1;
    else if(T->left != NULL){
        result = hasPathSum(T->left, sum - T->val);
        if(result == 1) return result;
        else if(T->right != NULL){
            result = hasPathSum(T->right, sum - T->val);
            return result;
        }
    }
    if(T->right != NULL){
        result = hasPathSum(T->right, sum - T->val);
        return result;
    }
}
