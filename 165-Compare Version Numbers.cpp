class Solution {
public:
    vector<int> version2int(string version){
        vector<int> result;
        size_t len = version.size();
        int dot = -1;
        size_t subcnt = 0;
        string substring;
        for(int i = 0; i <= len; i++){
            subcnt++;
            if(version[i] == '.' || version[i] == '\0'){
                substring = version.substr(dot + 1, subcnt - 1);
                dot = i;
                subcnt = 0;
                result.push_back(atoi(substring.c_str()));
            }
        }
        return result;
    }
    
    int compare(int x, int y){
        if(x > y) return 1;
        if(x == y) return 0;
        if(x < y) return -1;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> verint1 = version2int(version1);
        vector<int> verint2 = version2int(version2);
        
        int len = verint1.size() > verint2.size() ? verint1.size() : verint2.size();
        for(int i = verint1.size(); i < len; i++)
            verint1.push_back(0);
        for(int i = verint2.size(); i < len; i++)
            verint2.push_back(0);
        for(int i = 0; i < len; i++){
            if(compare(verint1[i], verint2[i]) == 0) continue;
            if(compare(verint1[i], verint2[i]) == 1) return 1;
            if(compare(verint1[i], verint2[i]) == -1) return -1;
        }
        return 0;
    }
};
