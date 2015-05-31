bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i, j;
    if(matrixRowSize == 0 || matrixColSize == 0) return false;
    for(i = 0; i < matrixRowSize; i++){
        if(target == matrix[i][0]) return true;
        else if(i - 1 >= 0 && target < matrix[i][0] && target > matrix[i - 1][0]) break;
        
    }
    for(j = 0; j < matrixColSize; j++){
        if(target == matrix[i - 1][j]) return true;
    }
    return false;
}
