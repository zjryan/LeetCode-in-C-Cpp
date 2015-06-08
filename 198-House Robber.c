static int max(int x, int y){
    return x > y ? x : y;
}

int rob(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];
    int* aux = (int*)malloc(sizeof(int) * numsSize);
    aux[0] = nums[0];
    aux[1] = max(nums[0], nums[1]);
    int i;
    for(i = 2; i < numsSize; i++)
        aux[i] = max(aux[i - 1], aux[i - 2] + nums[i]);
    int result = aux[numsSize - 1];
    free(aux);
    return result;
}
