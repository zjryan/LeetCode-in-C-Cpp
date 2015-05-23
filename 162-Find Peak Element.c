static int recursiveFind(int* nums, int l, int h, int numsSize){
    int subSize = h - l + 1;
    if(subSize == 1 && numsSize == subSize){
        return l;
    }
    else if(subSize == 2){
        if(l == 0 && nums[l] > nums[h]) return l;
        else if(h == numsSize - 1 && nums[h] > nums[l]) return h;
        else return -1;
    }
    int mid = (l + h) / 2;
    int subIndex;
    if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
        return mid;
    }
    else{
        subIndex = recursiveFind(nums, l, mid, numsSize);
        if(subIndex != -1) return subIndex;
        else{
            subIndex = recursiveFind(nums, mid, h, numsSize);
            return subIndex;
        }
    }
}

int findPeakElement(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    return recursiveFind(nums, low, high, numsSize);
}
