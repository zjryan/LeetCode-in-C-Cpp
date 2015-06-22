int countPrimes(int n) {
    int* prime = (int*)malloc(sizeof(int) * (n - 2));
    for(int i = 0; i < n - 2; i++)
        prime[i] = i + 2;
    for(int i = 0; i < n - 2; i++){
        if(prime[i] != 0) {
            int j = prime[i] * prime[i];
            while(j < n - 2){
                prime[j] = 0;
                j += prime[i];
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n - 2; i++)
        if(prime[i] != 0) cnt++;
    return cnt;
}
