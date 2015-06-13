int reverse(int x) {
    int sign = 1;
    long long tmp = x;
    if(tmp < 0){
        tmp = -tmp;
        sign = -1;
    }
    
    long long result = 0;
    while (tmp){
        result = result * 10 + tmp % 10;
        tmp /= 10;
    }
    result *= sign;
    if(result > INT_MAX || result < INT_MIN) return 0; 
    return result;
}
