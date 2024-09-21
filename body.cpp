#include <stdio.h>
#include <math.h>
#include "header.h"

// Fungsi untuk input elemen matriks
void inputMatrix(float matrix[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Masukkan elemen pada [%d, %d]: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

// Fungsi untuk menampilkan matriks dengan membulatkan nilai yang sangat kecil
void displayMatrix(float matrix[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Jika nilai sangat kecil (kurang dari 0.0001), tampilkan sebagai 0.000
            if (fabs(matrix[i][j]) < 0.0001) {
                printf("%8.3f ", 0.000);
            } else {
                printf("%8.3f ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Fungsi untuk melakukan eliminasi Gauss-Jordan dengan menampilkan langkah-langkah
void gaussJordan(float matrix[MAX][MAX], int n, int m, int showSteps) {
    int i, j, k;
    float temp;

    for (i = 0; i < n; i++) {
        // Membuat elemen diagonal menjadi 1
        temp = matrix[i][i];
        if (temp != 0) {
            for (j = 0; j < m; j++) {
                matrix[i][j] /= temp;
            }

            if (showSteps) {
                printf("\nMembagi baris %d dengan %.3f untuk membuat elemen [%d][%d] menjadi 1:\n", i+1, temp, i+1, i+1);
                displayMatrix(matrix, n, m);
            }
        }

        // Membuat elemen di atas dan di bawah diagonal menjadi 0
        for (k = 0; k < n; k++) {
            if (k != i) {
                temp = matrix[k][i];
                for (j = 0; j < m; j++) {
                    matrix[k][j] -= matrix[i][j] * temp;
                }

                if (showSteps) {
                    printf("\nMengurangkan %.3f kali baris %d dari baris %d untuk membuat elemen [%d][%d] menjadi 0:\n", temp, i+1, k+1, k+1, i+1);
                    displayMatrix(matrix, n, m);
                }
            }
        }
    }
}
