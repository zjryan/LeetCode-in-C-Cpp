int searchInsert(int* nums, int numsSize, int target) {
    int l = 0;
    int h = numsSize - 1;
    int mid;
    int p = 0;
    while(h != -1){
        if(l >= h){
            if(nums[l] < target){
                p = l + 1;
                break;
            }
            else if(nums[l] >= target){
                p = l;
                break;
            }
        }
        mid = (l + h) / 2;
        if(nums[mid] > target){
            h = mid - 1;
        }
        else if(nums[mid] == target){
            p = mid;
            break;
        }
        else{
            l = mid + 1;
        }
    }
    return p;
}
