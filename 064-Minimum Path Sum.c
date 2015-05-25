static int min(int x, int y){
    return x < y ? x : y;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i, j;
    if(gridRowSize == 0 || gridColSize == 0) return 0;
    
    for(j = 1; j < gridColSize; j++){
        grid[0][j] += grid[0][j - 1];
    }
    for(i = 1; i < gridRowSize; i++){
        grid[i][0] += grid[i - 1][0];
    }
    for(i = 1; i < gridRowSize; i++){
        for(j = 1; j < gridColSize; j++){
            int smaller = min(grid[i][j - 1], grid[i - 1][j]);
            grid[i][j] += smaller;
        }
    }
    return grid[gridRowSize - 1][gridColSize - 1];
}
