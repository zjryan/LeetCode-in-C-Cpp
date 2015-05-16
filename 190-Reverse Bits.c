uint32_t reverseBits(uint32_t n) {
    uint32_t maskl = 0x80000000;
    uint32_t maskr = 0x00000001;
    uint32_t convertl, convertr;
    uint32_t result = 0x00000000;
    int i;
    for(i = 0; i < 16; i++){
        convertl = n & maskl;
        convertr = n & maskr;
        convertl = convertl >> (31 - 2 * i);
        convertr = convertr << (31 - 2 * i);
        result = result | convertl | convertr;
        maskl = maskl >> 1;
        maskr = maskr << 1;
    }
    return result;
}
