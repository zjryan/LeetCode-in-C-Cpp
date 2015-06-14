int myAtoi(char* str) {
    int i, sign;
    for(i = 0; isspace(str[i]); i++) ;
    if(str[i] == '-' || str[i] == '+'){
        sign = str[i] == '-' ? - 1 : 1;
        i++;
    }
    else sign = 1;
    long long n = 0;
    int power = 0;
    for(; isdigit(str[i]); i++){
        n = n * 10 + str[i] - '0';
        if (n > INT_MAX){
			n = (long long)INT_MAX + 1;
			break;
		}
    }
    n *= sign;
    if(n > INT_MAX) return INT_MAX;
    else if(n < INT_MIN) return INT_MIN;
    return (int)n;
}
