class Solution {
public:
    string addBinary(string a, string b) {
        string augend = a.size() > b.size() ? a : b;
        string addend = a.size() <= b.size() ? a : b;
        //assert length of addend is always not greater than augend
        int diff = augend.size() - addend.size();
        int h = addend.size() - 1;
        while(h >= 0){
            augend[h + diff] += (addend[h] - '0');
            processcarry(augend, h + diff);
            diff = augend.size() - addend.size();
            h--;
        }
        return augend;
    }
private:
    void processcarry(string &augend, int h){
        if(augend[h] != '2') return;
        else{
            augend[h] = '0';
            if(--h >= 0){
                augend[h]++;
                processcarry(augend, h);
            }
            else{
                augend = '1' + augend;
            }
        }
    }
};
