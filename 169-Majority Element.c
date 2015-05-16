static void insertionSort(int* nums, int numsSize){
    int i,j;
    for(j = 1; j < numsSize; j++){
        i = j - 1;
        int key = nums[j];
        while(i >= 0 && nums[i] > key){
            nums[i + 1] = nums[i];
            i = i - 1;
        }
        nums[i + 1] = key;
    }
}

int majorityElement(int* nums, int numsSize) {
    insertionSort(nums, numsSize);
    return nums[numsSize/2];
}
