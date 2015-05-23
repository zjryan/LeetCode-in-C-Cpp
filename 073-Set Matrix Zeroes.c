#define ZEROFLAG (-6501)
#define ZEROROW (-6500)
#define ZEROCOL (-6549)

//this implementation use constant space
static void setFlag(int** matrix, int row, int col){
    if(row == 0 && col == 0) matrix[0][0] = ZEROFLAG;
    else if(row == 0){
        if(matrix[0][0] != ZEROFLAG && 
        matrix[0][0] != ZEROCOL) matrix[0][0] = ZEROROW;
        else if(matrix[0][0] != ZEROFLAG && 
             matrix[0][0] == ZEROCOL) matrix[0][0] = ZEROFLAG;
        matrix[0][col] = ZEROFLAG;
    } 
    else if(col == 0){
        if(matrix[0][0] != ZEROFLAG && 
        matrix[0][0] != ZEROROW) matrix[0][0] = ZEROCOL;
        else if(matrix[0][0] != ZEROFLAG && 
             matrix[0][0] == ZEROROW) matrix[0][0] = ZEROFLAG;
        matrix[row][0] = ZEROFLAG;
    }
    else{
        matrix[row][0] = ZEROFLAG;
        matrix[0][col] = ZEROFLAG;        
    }
}

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j;
    for(i = 0; i < matrixRowSize; i++){
        for(j = 0; j < matrixColSize; j++){
            if(matrix[i][j] == 0){
                setFlag(matrix, i, j);
            }
        }
    }
    int beginRow, beginCol;
    if(matrix[0][0] == ZEROFLAG) { beginRow = 1; beginCol = 1;}
    else if(matrix[0][0] == ZEROROW) { beginRow = 1; beginCol = 0;}
    else if(matrix[0][0] == ZEROCOL) { beginCol = 1; beginRow = 0;}
    else { beginRow = 0; beginCol = 0;}
    
    for(j = beginRow; j < matrixColSize; j++){
        if(matrix[0][j] == ZEROFLAG){
            for(i = 0; i < matrixRowSize; i++){
                matrix[i][j] = 0;
            }
        }
    }
    for(i = beginCol; i < matrixRowSize; i++){
        if(matrix[i][0] == ZEROFLAG){
            for(j = 0; j < matrixColSize; j++){
                matrix[i][j] = 0;
            }
        }
    }
    
    if(matrix[0][0] == ZEROFLAG){
        for(j = 0; j < matrixColSize; j++){
            matrix[0][j] = 0;
        }
        for(i = 0; i < matrixRowSize; i++){
            matrix[i][0] = 0;
        }
    }
    else if(matrix[0][0] == ZEROROW){
        for(j = 0; j < matrixColSize; j++){
            matrix[0][j] = 0;
        }        
    }
    else if(matrix[0][0] == ZEROCOL){
        for(i = 0; i < matrixRowSize; i++){
            matrix[i][0] = 0;
        }        
    }
}
