int findMin(int* nums, int numsSize) {
    int i;
    int min = nums[0];
    for(i = 1; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    return min;
}
