#include <stdio.h>
#include "header.h"

int main() {
    int n, m, showSteps;
    float matrix[MAX][MAX], matrixCopy[MAX][MAX];
    
    // Get matrix dimensions from the user
    printf("Masukkan jumlah baris (n): ");
    scanf("%d", &n);
    printf("Masukkan jumlah kolom (m): ");
    scanf("%d", &m);

    // Input matrix elements
    inputMatrix(matrix, n, m);

    // Copy the original matrix to display after elimination
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrixCopy[i][j] = matrix[i][j];
        }
    }

    // Display the input matrix
    printf("\nMatriks yang dimasukkan adalah:\n");
    displayMatrix(matrix, n, m);

    // Perform Gauss-Jordan elimination without showing steps
    gaussJordan(matrixCopy, n, m, 0);

    // Display the result of Gauss-Jordan elimination
    printf("\nHasil matriks setelah eliminasi Gauss-Jordan (dalam bentuk eselon baris tereduksi):\n");
    displayMatrix(matrixCopy, n, m);

    // Ask if user wants to see the steps
    printf("\nApakah Anda ingin menampilkan langkah-langkah penyelesaian? (1 = Ya, 0 = Tidak): ");
    scanf("%d", &showSteps);

    if (showSteps) {
        printf("\nLangkah-langkah eliminasi Gauss-Jordan:\n");
        gaussJordan(matrix, n, m, 1); // Show steps
    }

    return 0;
}
