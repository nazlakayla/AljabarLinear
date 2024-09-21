#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>

#define MAX 10

// Function declarations
void inputMatrix(float matrix[MAX][MAX], int n, int m);
void displayMatrix(float matrix[MAX][MAX], int n, int m);
void gaussJordan(float matrix[MAX][MAX], int n, int m, int showSteps);

#endif // HEADER_H
