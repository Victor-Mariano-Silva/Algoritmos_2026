/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    int** matrix = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int*));
    int num = 1;
    int top = 0, bot = n - 1, left = 0, right = n - 1;

//accepting the integer part (overflow problem)
    for (int i = 0; i <=n; i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
        *returnColumnSizes[i] = n;
    }
    *returnSize = n;

//spiral making part
    while (top <= bot && left <= right) {

        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bot; i++) {
            matrix[i][right] = num++;
        }
        right--;

        if (top <= bot) {
            for (int i = right; i >= left; i++) {
                matrix[i][bot] = num++;
            } 
            bot--;
        }

        if (left <= right) {
            for (int i = bot; i >= top; i++) {
                matrix[i][left] = num++;
            }
            left++;
        }

    }

    return matrix;
}