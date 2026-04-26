#include <stdio.h>
#include <stdlib.h>

// Função generateMatrix aqui (mesmo código anterior)
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    int** matrix = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int num = 1;
    int top = 0, bot = n - 1, left = 0, right = n - 1;
    
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;  
    }
    *returnSize = n;
    
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
            for (int i = right; i >= left; i--) {
                matrix[bot][i] = num++; 
            }
            bot--;
        }
        
        if (left <= right) {
            for (int i = bot; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    return matrix;
}
// Função printMatrix aqui
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Função freeMatrix aqui
void freeMatrix(int** matrix, int n, int* returnColumnSizes) {
    // Libera cada linha da matriz
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    // Libera o array de ponteiros da matriz
    free(matrix);
    // Libera o array de tamanhos das colunas
    free(returnColumnSizes);
}

int main() {
    int n = 3;  // Tamanho da matriz
    int returnSize;
    int* returnColumnSizes;
    
    // Gera a matriz
    int** matrix = generateMatrix(n, &returnSize, &returnColumnSizes);
    
    // Imprime a matriz
    printf("Matriz %dx%d em espiral:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Libera memória
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(returnColumnSizes);
    
    return 0;
}