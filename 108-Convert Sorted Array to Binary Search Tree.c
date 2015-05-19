//divide & conquer algorithm
static struct TreeNode* recursiveTrans(int* nums, int l, int h, int arraySize){
    int subArraySize = h - l + 1;
    if(arraySize == 0 || subArraySize == 0){
        return NULL;
    }
    
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct newNode*));
    struct TreeNoed* newLeft;
    struct TreeNode* newRight;
    
    //divide
    int mid = (l + h) / 2;
    //assert newNode != NULL
    //conquer
    newNode->val = nums[mid];
    newLeft = recursiveTrans(nums, l, mid - 1, arraySize);
    newRight = recursiveTrans(nums, mid + 1, h, arraySize);
    //combine
    newNode->left = newLeft;
    newNode->right = newRight;
    
    return newNode;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    struct TreeNode* BST;
    BST = recursiveTrans(nums, low, high, numsSize);
    return BST;
}
