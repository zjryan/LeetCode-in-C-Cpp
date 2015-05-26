class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t len = s.size();
        int i = 0;
        int wordSize, lastWordSize;
        wordSize = lastWordSize = 0;
        while (i < len){
            while(s[i] != ' '){
                wordSize++;
                i++;
                if(i >= len) break;
            }
            while(s[i] == ' '){
                i++;
            }
            lastWordSize = wordSize;
            wordSize = 0;
        }
        return lastWordSize;
    }
};
