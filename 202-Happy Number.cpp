class Solution {
public:
    int square(int digit){
    	return digit * digit;
    }
    
    int numDigits(int n){
    	int cnt = 0;
    	while (n != 0){
    		cnt++;
    		n /= 10;
    	}
    	return cnt;
    }
    
    bool isHappy(int n) {
    	int numdigit = numDigits(n);
    	int sumOfSquare = 0;
    	int i;
    	std::vector<int> listnums;
    
    	for (;;){
    		for (i = 0; i < numdigit; i++){
    			sumOfSquare += square(n % 10);
    			n = n / 10;
    		}
    		if (sumOfSquare == 1){
    			return 1;
    		}
    		else if (find(listnums.begin(), listnums.end(), sumOfSquare) != listnums.end()){
    			return 0;
    		}
    		else{
    			listnums.push_back(sumOfSquare);
    			n = sumOfSquare;
    			sumOfSquare = 0;
    			numdigit = numDigits(n);
    		}
    	}
    }   
};
