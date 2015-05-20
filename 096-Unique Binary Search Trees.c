int numTrees(int n) {
    int* aux = (int*)malloc(sizeof(int) * n);
    aux[0] = 1;
    int i, j;
    for(i = 1; i < n; i++){
        aux[i] = 2 * aux[i - 1];
        for(j = i - 1; j > 0; j--){
            aux[i] += aux[i - 1 - j] * aux[j - 1];
        }
    }
    int result = aux[n - 1];
    free(aux);
    return result;
}
