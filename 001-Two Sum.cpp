class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return {};
        multimap<int, int> hashtable;
        for(int i = 0; i < len; i++)
            hashtable.insert({nums[i], i});
        vector<int> result;
        for(auto elem : hashtable)
            if(target > 0 && elem.first > target) continue;
            else if(target < 0 && elem.first < target) continue;
            else{
                if(hashtable.find(target - elem.first) != hashtable.end()){
                    result.push_back(hashtable.lower_bound(target - elem.first)->second + 1);
                    result.push_back((--hashtable.upper_bound(elem.first))->second + 1);
                    if(result[0] > result[1]) reverse(result.begin(), result.end());
                    return result;
                }
            }
        return result;
    }
};Two Sum 
