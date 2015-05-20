void sortColors(int* nums, int numsSize) {
    int i, j;
    int key;
    for(j = 1; j < numsSize; j++){
        key = nums[j];
        i = j - 1;
        while(i >= 0 && nums[i] > key){
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = key;
    }
}
