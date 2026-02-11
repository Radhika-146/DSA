Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Code:
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced.
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {
    
    int m = matrixSize;          // number of rows
    int n = matrixColSize[0];    // number of columns

    // Transposed matrix will be n x m
    *returnSize = n;

    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    // Allocate memory for result matrix
    int** result = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        result[i] = (int*)malloc(m * sizeof(int));
    }

    // Fill transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
