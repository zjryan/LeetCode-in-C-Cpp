static int max(int x, int y){
    return x > y ? x : y;
}

bool canJump(int* nums, int numsSize) {
    if (numsSize == 0)
        return false;
        
    int step = nums[0];
    
    for(int i = 1; i < numsSize; i++)
        if (step > 0)
        {
            step--;
            step = max(step, nums[i]);
        }
        else
            return false;
            
    return true;
}
