class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<set<string>> aux = { {"()"} };
        for(int i = 1; i < n; i++){
            set<string> pari;
            string newstr;
            for(auto elem : aux[i - 1]){
                newstr = "(" + elem + ")";
                pari.insert(newstr);
            }
            for(int j = i - 1; j >= 0; j--){
                for(auto elemj : aux[j]){
                    for(auto elemk : aux[i - j - 1]){
                        newstr = elemj + elemk;
                        pari.insert(newstr);
                        newstr = elemk + elemj;
                        pari.insert(newstr);
                    }
                }
            }
            aux.push_back(pari);
        }
        vector<string> result;
        for(auto elem : aux[n - 1])
            result.push_back(elem);
        return result;
    }
};
