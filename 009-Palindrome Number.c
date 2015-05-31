bool isPalindrome(int x) {
    if(x < 0) return false;
    long long tmp = x;
    long long reversedx = 0;
    while(tmp){
        reversedx = reversedx * 10 + tmp % 10;
        tmp /= 10;
    }
    if(reversedx == x) return true;
    else return false;
}
