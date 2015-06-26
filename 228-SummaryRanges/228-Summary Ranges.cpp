class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        size_t len = nums.size();
        int beg, end;
        vector<string> result;
        
        if(len == 0) {
            return result;
        }
        beg = end = nums[0];
        if(len == 1) {
            result.push_back(to_string(beg));
            return result;
        }
        
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[i - 1] + 1){
                string tmp;
                if(beg != end){
                    tmp = to_string(beg) + "->" + to_string(end);
                }
                else {
                    tmp = to_string(beg);
                }
                result.push_back(tmp);
                beg = nums[i];
                end = nums[i];
                if(i == len - 1){
                    result.push_back(to_string(nums[i]));
                }
            }
            else{
                end = nums[i];
                if(i == len - 1){
                    string tmp = to_string(beg) + "->" + to_string(end);
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};
