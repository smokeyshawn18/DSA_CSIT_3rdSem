#include <stdio.h>
#include <math.h>

#define MAX 100

int main() {
    float A[MAX][MAX], x[MAX], rhs[MAX], ratio;
    int i, j, k, n;

    printf("Shudarsan Poudel\n");
    printf("Gauss Elimination Method\n\n");

    // Step 1: Input number of equations
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
        scanf("%f", &rhs[i]);
        A[i][n] = rhs[i]; // Appending RHS to form augmented matrix
    }

    // Step 4: Forward Elimination
    for (i = 0; i < n - 1; i++) {
        if (A[i][i] == 0.0) {
            printf("Mathematical Error: Division by zero.\n");
            return 1;
        }

        for (j = i + 1; j < n; j++) {
            ratio = A[j][i] / A[i][i];
            for (k = i; k <= n; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    // Step 5: Back Substitution
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--) {
        x[i] = A[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Step 6: Output Result
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    printf("\nShudarsan Poudel\n");
    return 0;
}
