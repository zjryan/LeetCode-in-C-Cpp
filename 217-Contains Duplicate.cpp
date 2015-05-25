class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> numsCount;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int cnt = ++numsCount[nums[i]];
            if(cnt > 1) return true;
        }
        return false;
    }
};
