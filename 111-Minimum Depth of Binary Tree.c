/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    struct TreeNode* T = root;
    int node, ln, rn;
    node = ln = rn = 0;
    if(T == NULL) return 0;
    //assert T is not NULL
    node = 1;
    if(T->left){
        ln += minDepth(T->left);
    }
    if(T->right){
        rn += minDepth(T->right);
    }
    int smaller;
    if(T->left && T->right)
        smaller = ln < rn ? ln : rn;
    else if(T->left == NULL)
        smaller = rn;
    else smaller = ln;
    
    node += smaller;
    return node;
}
