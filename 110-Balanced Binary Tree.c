static int max(int x, int y){
    return (x > y ? x : y);    
}

static int min(int x, int y){
    return (x < y ? x : y);
}

static int getNodeHeight(struct TreeNode* node){
    struct TreeNode* T = node;
    int height = 0;
    int lh = 0;
    int rh = 0;
    if(T != NULL && (T->left != NULL || T->right != NULL)){
        height = 1;
        if(T->left != NULL){
            lh = getNodeHeight(T->left);
        }
        if(T->right != NULL){
            rh = getNodeHeight(T->right);
        }
        height += max(lh, rh);
    }
    return height;
} 

bool isBalanced(struct TreeNode* root) {
    struct TreeNode* T = root;
    int lefth, righth;
    bool result = true;
    lefth = righth = 0;
    
    if(T != NULL && (T->left != NULL || T->right != NULL)){
        if(T->left != NULL){
            lefth = getNodeHeight(T->left) + 1;
        }
        if(T->right != NULL){
            righth = getNodeHeight(T->right) + 1;
        }
        if(abs(lefth - righth) > 1){
            return false;
        }
        if(T->left != NULL){
            result = isBalanced(T->left);
            if(result == false) return false;
        }
        if(T->right != NULL){
            result = isBalanced(T->right);
            if(result == false) return false;
        }
    }
    return result;
}
