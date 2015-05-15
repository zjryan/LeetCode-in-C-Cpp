/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 static int Max(int a, int b){
     return a > b ? a : b;
 }
 
int maxDepth(struct TreeNode* root) {
    struct TreeNode* T = root;
    if (T == NULL){
        return 0;
    }
    else{
        int cnt = 1;
        int larger = 0;
        if (T->left != NULL){
            cnt = maxDepth(T->left) + 1;
            larger = Max(larger, cnt);          
        }
        if(T->right != NULL){
            cnt = maxDepth(T->right) + 1;
        }
        larger = Max(larger, cnt); 
        return larger;
    }
}
