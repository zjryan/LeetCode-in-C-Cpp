int maxSubArray(int* nums, int numsSize) {
    int i;
    int sum = nums[0];
    int maxSum = nums[0];
    for(i = 1; i < numsSize; i++){
        if(sum < 0){
            sum = 0;
        }
        sum += nums[i];
        maxSum = (maxSum > sum ? maxSum : sum);
    }
    return maxSum;
}
