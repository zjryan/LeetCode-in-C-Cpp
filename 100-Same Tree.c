/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p != NULL && q != NULL){
        if (p->val != q->val){
            return 0;
        }
        else{
            int flag = isSameTree(p->left, q->left);
            if (flag == 0){
                return 0;
            }
            else{
                flag = isSameTree(p->right, q->right);
                if(flag == 0){
                    return 0;
                }
            }
        }
    }
    else if(p == NULL && q == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
