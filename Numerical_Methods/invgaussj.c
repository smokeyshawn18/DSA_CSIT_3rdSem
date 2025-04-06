#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main() {
    float A[MAX][2 * MAX], ratio;
    int i, j, k, n;

    printf("Shudarsan Poudel\n");
    printf("Matrix Inversion using Gauss-Jordan Method\n\n");

    // Step 1: Input matrix size
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    // Step 2: Input the matrix
    printf("Enter the elements of the matrix row-wise:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Step 3: Augment with identity matrix
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            A[i][j] = (i == (j - n)) ? 1.0 : 0.0;
        }
    }

    // Step 4: Apply Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        float pivot = A[i][i];
        if (pivot == 0.0) {
            printf("Mathematical Error: Pivot element is zero, matrix is not invertible.\n");
            return 1;
        }

        // Normalize the pivot row
        for (j = 0; j < 2 * n; j++) {
            A[i][j] /= pivot;
        }

        // Make all other rows 0 in the current column
        for (k = 0; k < n; k++) {
            if (k != i) {
                ratio = A[k][i];
                for (j = 0; j < 2 * n; j++) {
                    A[k][j] -= ratio * A[i][j];
                }
            }
        }
    }

    // Step 5: Display the inverse matrix
    printf("\nInverse of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            printf("%8.4f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nShudarsan Poudel\n");
    return 0;
}
