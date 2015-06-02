int singleNumber(int* nums, int numsSize) {
    int i;
    int one, two, three;
    one = two = three = 0;
    for(i = 0; i < numsSize; i++){
        three = two & nums[i];
        two = two | one & nums[i];
        one = one | nums[i];
        one = one & ~three;
        two = two & ~three;
    }
    return one;
}
