int titleToNumber(char* s) {
	int length = 0;
	int i;
	for (i = 0; s[i] != '\0'; i++){
		length++;
	}
	int cnt = 0;
	int j;
	for (i = 0; i < length; i++){
		int factor = 1;
		for (j = length - i - 1; j > 0; j--){
			factor *= 26;
		}
		cnt += ((int)s[i] - 64) * factor;
	}
	return cnt;
}
