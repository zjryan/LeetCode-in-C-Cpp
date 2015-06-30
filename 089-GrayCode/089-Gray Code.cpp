class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return { 0 };
        vector<string> L1 = {"0", "1"};
        int cnt = 1;
        while(cnt < n){
            vector<string> L2(L1);
            reverse(L2.begin(), L2.end());
            for(auto &elem : L1)
                elem = "0" + elem;
            for(auto &elem : L2){
                elem = "1" + elem;
                L1.push_back(elem);
            }
            cnt++;
        }
        vector<int> result;
        for(auto elem : L1)
            result.push_back(btod(elem));
        return result;
    }
private:
    int btod(string bin){
        size_t len = bin.size();
        int result = 0;
        for(int i = len - 1; i >= 0; i--){
            result += (bin[i] - '0') << (len - 1 - i);
        }
        return result;
    }
};
