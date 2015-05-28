int strStr(char* haystack, char* needle) {
    int i, j, k;
    if(needle == NULL || haystack == NULL) return -1;
    for(i = j = 0; haystack[i] != '\0' && needle[j] != '\0';){
        if(haystack[i] == needle[j]){
            j++;
            i++;
        }
        else{
            i = i - j + 1; 
            j = 0;
        }
    }
    if(needle[j] == '\0') return i - j;
    else return -1;
}
