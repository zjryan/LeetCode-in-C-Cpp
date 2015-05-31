int uniquePaths(int m, int n) {
    int i, j;
    if(m == 0 || n == 0) return 0;
    int** grid = (int**)malloc(sizeof(int*) * m);
    for(i = 0; i < m; i++){
        int* row = (int*)malloc(sizeof(int) * n);
        grid[i] = row;
        grid[i][0] = 1;
    }
    for(j = 0; j < n; j++){
        grid[0][j] = 1;
    }
    for(i = 1; i < m; i++){
        for(j = 1; j < n; j++){
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    int result = grid[m - 1][n - 1];
    free(grid);
    return result;
}
