class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), specialCmp);
        string result;
        if(nums[0] == 0) return "0";
        for(int elem : nums)
            result += to_string(elem);
        return result;
    }
private:    
    static bool specialCmp(int x, int y){
	string c1 = to_string(x) + to_string(y);
	string c2 = to_string(y) + to_string(x);
	return c1 > c2;
    }
};
