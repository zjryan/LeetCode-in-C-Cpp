int hammingWeight(uint32_t n) {
    int cnt = 0;
    int mask = 1;
    for(int i = 0; i < 32; i++){
        if(n & mask){
            cnt++;
        }
        mask = mask << 1;
    }
    return cnt;
}
