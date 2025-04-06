#include <stdio.h>

#define MAX 10

int main() {
    float A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];
    int i, j, k, n;

    printf("Shudarsan Poudel\n");
    printf("Doolittle LU Decomposition Method\n\n");

    // Input matrix size
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix A
    printf("Enter the elements of the matrix A row-wise:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Initialize L and U matrices to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Perform Doolittle LU Decomposition
    for (i = 0; i < n; i++) {
        // Upper Triangular Matrix U
        for (k = i; k < n; k++) {
            float sum = 0;
            for (j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular Matrix L
        for (k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                float sum = 0;
                for (j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                if (U[i][i] == 0) {
                    printf("Zero pivot encountered. Cannot proceed.\n");
                    return 1;
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    // Print L matrix
    printf("\nLower Triangular Matrix L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.4f ", L[i][j]);
        }
        printf("\n");
    }

    // Print U matrix
    printf("\nUpper Triangular Matrix U:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.4f ", U[i][j]);
        }
        printf("\n");
    }

    printf("\nShudarsan Poudel\n");
    return 0;
}
