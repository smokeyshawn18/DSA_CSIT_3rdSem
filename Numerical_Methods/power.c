#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
    float A[MAX][MAX], x[MAX], x_new[MAX], lambda, lambda_old, error;
    int n, i, j, step = 1, max_steps;

    printf("Shudarsan Poudel\n");
    printf("Power Method for Dominant Eigenvalue and Eigenvector\n\n");

    // Input matrix size
    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix A
    printf("Enter the elements of the matrix A row-wise:\n");
    for (i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Input initial guess vector x0
    printf("\nEnter the initial guess vector x0:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Input tolerance and maximum number of iterations
    printf("\nEnter the tolerance and maximum number of iterations: ");
    scanf("%f %d", &error, &max_steps);

    lambda_old = 0;  // Initial guess for eigenvalue

    printf("\nStep\tEigenvalue\n");

    // Power Method Iterations
    while (step <= max_steps) {
        // Multiply A * x
        for (i = 0; i < n; i++) {
            x_new[i] = 0;
            for (j = 0; j < n; j++) {
                x_new[i] += A[i][j] * x[j];
            }
        }

        // Find the dominant eigenvalue (approximate)
        lambda = fabs(x_new[0]);
        for (i = 1; i < n; i++) {
            if (fabs(x_new[i]) > lambda)
                lambda = fabs(x_new[i]);
        }

        // Normalize the new vector
        for (i = 0; i < n; i++) {
            x_new[i] = x_new[i] / lambda;
        }

        // Check for convergence
        float diff = fabs(lambda - lambda_old);
        printf("%d\t%f\n", step, lambda);

        if (diff < error)  // If change in eigenvalue is less than tolerance, stop the iterations
            break;

        // Prepare for next iteration
        for (i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        lambda_old = lambda;
        step++;
    }

    printf("\nDominant Eigenvalue = %f\n", lambda);
    printf("Corresponding Eigenvector:\n");
    for (i = 0; i < n; i++) {
        printf("%f\n", x_new[i]);
    }

    printf("\nShudarsan Poudel\n");

    return 0;
}
