#include <stdio.h>
#include <math.h>

// Define G(x) = (a3*x^3 + a2*x^2 + a0) / -a1
#define G(x) ((a3 * (x) * (x) * (x) + a2 * (x) * (x) + a0) / (-a1))

int main() {
    // Declare variables
    float a0, a1, a2, a3;  // Coefficients of the equation
    float x0, x1, error, tolerance;  // Iteration variables
    int max_iterations, step = 1;   // Iteration control

    // Print programmer's name
    printf("========================================\n");
    printf("      Fixed Point Iteration Method\n");
    printf("========================================\n");


    // Input section
    printf("Enter coefficients (a3, a2, a1, a0) for equation:\n");
    printf("a3*x^3 + a2*x^2 + a1*x + a0 = 0\n");
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);

    // Check for division by zero in G(x)
    if (a1 == 0) {
        printf("Error: Division by zero in G(x) due to a1 = 0.\n");
        return 1;
    }

    printf("\nEnter initial guess (x0): ");
    scanf("%f", &x0);

    printf("Enter tolerable error: ");
    scanf("%f", &tolerance);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Display user inputs
    printf("\nUser Inputs:\n");
    printf("Equation Coefficients: a3 = %.2f, a2 = %.2f, a1 = %.2f, a0 = %.2f\n", a3, a2, a1, a0);
    printf("Initial Guess: x0 = %.6f\n", x0);
    printf("Tolerable Error: E = %.6f\n", tolerance);
    printf("Maximum Iterations: %d\n", max_iterations);

    // Table header for iterations
    printf("\n%-5s %-12s %-12s %-12s\n", "Step", "x₀", "x₁", "Error");
    printf("----------------------------------------\n");

    // Iteration loop
    while (step <= max_iterations) {
        x1 = G(x0);  // Compute next approximation using G(x)

        // Calculate error
        error = fabs(x1 - x0);

        // Print current step details
        printf("%-5d %-12.6f %-12.6f %-12.6f\n", step, x0, x1, error);

        // Check for convergence
        if (error < tolerance) {
            printf("\nRoot found: %.6f\n", x1);
            printf("Converged in %d iterations.\n", step);
            printf("\nShudarsan Poudel\n");
            return 0;
        }

        // Update x0 for next iteration
        x0 = x1;
        step++;
    }

    // If not converged within max_iterations
    printf("\nThe method did not converge within %d iterations.\n", max_iterations);
    printf("Last approximation: %.6f\n", x1);
    
    return 1;
}
