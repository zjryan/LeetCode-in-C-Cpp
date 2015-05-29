int trailingZeroes(int n) {
    int result = 0;
    int i;
    while(n){
        result += n / 5;
        n /= 5;
    }
    return result;
}
