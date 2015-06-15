static vector<string> units{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
static vector<string> tens{"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
static vector<string> hundreds{"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
static vector<string> thousands{"M", "MM", "MMM"};

class Solution {
public:
    int numsOfDigits(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    
    string intToRoman(int num) {
        int digits = numsOfDigits(num);
        string result = "";
        int currentDigits = digits;
        switch(digits){
        case 4:{
                result += thousands[num / 1000 - 1];
                num = num % 1000;
                //fall through
        }
        case 3:{
                currentDigits = numsOfDigits(num);
                if(currentDigits == 3){
                    result += hundreds[num / 100 - 1];
                    num = num % 100;
                }
                //fall through
        }
        case 2:{
                currentDigits = numsOfDigits(num);
                if(currentDigits == 2){
                    result += tens[num / 10 - 1];
                    num = num % 10;
                }
                //fall through
        }
        case 1:{
                currentDigits = numsOfDigits(num);
                if(currentDigits == 1){
                    result += units[num - 1];
                }
                break;
        }
        default:break;
        }
        return result;
    }
};
