static void swapElems(int* nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
    int begin = 0;
    int end = numsSize - 1;
    while(begin <= end){
        if(nums[begin] == val){
            swapElems(nums, begin, end);
            end--;
        }
        else{
            begin++;
        }
    }
    return begin;
}
