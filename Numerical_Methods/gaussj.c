#include <stdio.h>
#include <math.h>

#define MAX 100

int main() {
    float A[MAX][MAX], ratio;
    int i, j, k, n;

    printf("Shudarsan Poudel\n");
    printf("Gauss-Jordan Elimination Method\n\n");

    // Step 1: Input number of unknowns
    printf("Enter the number of unknowns (equations): ");
    scanf("%d", &n);

    // Step 2: Input coefficient matrix row-wise
    printf("Enter the coefficients row-wise (one row per line):\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Step 3: Input RHS vector
    printf("Enter the RHS vector (separated by spaces):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &A[i][n]); // Appending RHS to form augmented matrix
    }

    // Step 4: Gauss-Jordan Elimination
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1
        float pivot = A[i][i];
        if (pivot == 0.0) {
            printf("Mathematical Error: Pivot element is zero.\n");
            return 1;
        }
        for (j = 0; j <= n; j++) {
            A[i][j] /= pivot;
        }

        // Make other elements in column i zero
        for (k = 0; k < n; k++) {
            if (k != i) {
                ratio = A[k][i];
                for (j = 0; j <= n; j++) {
                    A[k][j] -= ratio * A[i][j];
                }
            }
        }
    }

    // Step 5: Output Solution
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, A[i][n]);
    }

    printf("\nShudarsan Poudel\n");
    return 0;
}
