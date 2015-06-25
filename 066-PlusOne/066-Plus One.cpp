class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        int h = result.size() - 1;
        result[h]++;
        processCarry(result, h);
        return result;
    }
    
    void processCarry(vector<int>& result, int i){
        if(result[i] != 10) return;
        else{
            result[i] = 0;
            if(i - 1 >= 0){
                result[i - 1]++;
                processCarry(result, i - 1);
            }
            else{
                result.insert(result.begin(), 1);
            }
        }
    }
};
