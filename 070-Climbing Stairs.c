int climbStairs(int n) {
    int* Fib = (int*)malloc(sizeof(int) * (n + 1));
    Fib[0] = Fib[1] = 1;
    int i;
    for(i = 2; i < n + 1; i++){
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    int result = Fib[n];
    free(Fib);
    return result;
}
