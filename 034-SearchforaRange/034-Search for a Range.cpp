class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.size() == 0) return result;
        int tari = binarysearch(nums, target);
        if(tari == -1) return result;
        else{
            int l, r;
            l = r = tari;
            while(l >= 0 && nums[l] == target) l--;
            while(r < nums.size() && nums[r] == target) r++;
            result[0] = l + 1;
            result[1] = r - 1;
            return result;
        }
    }
private:
    int binarysearch(vector<int>& nums, int target){
        int l = 0;
        int h = nums.size() - 1;
        int mid;
        while(l <= h){
            mid = (l + h) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) h = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};
