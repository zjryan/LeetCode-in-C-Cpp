int search(int* nums, int numsSize, int target) {
    int i;
    if(numsSize == 0) return -1;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == target) return i;
    }
    return -1;
}
