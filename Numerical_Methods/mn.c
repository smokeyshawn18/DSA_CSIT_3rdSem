#include<stdio.h>
#include<math.h>

// Function f(x) that defines the equation
float f(float x) {
    return 3 * x - cos(x) - 1;
}

// Regula Falsi method implementation
void regula(float *x, float x0, float x1, float fx0, float fx1, int *itr) {
    // Formula for Regula Falsi method
    *x = x0 - ((x1 - x0) / (fx1 - fx0)) * fx0;
    ++(*itr);
    // Printing the iteration number and current value of x
    printf("Iteration no. %3d X = %7.5f \n", *itr, *x);
}

int main() {
    int itr = 0, maxitr;
    float x0, x1, x2, x3, allerr;

    // Input the initial values of x0, x1, allowed error, and maximum iterations
    printf("\nEnter the values of x0, x1, allowed error and maximum iterations:\n");
    scanf("%f %f %f %d", &x0, &x1, &allerr, &maxitr);

    // Initial call to the regula function to get the first approximation
    regula(&x2, x0, x1, f(x0), f(x1), &itr);

    do {
        // Determine the next x0 and x1 based on the sign of the function
        if (f(x0) * f(x2) < 0)
            x1 = x2;
        else
            x0 = x2;

        // Call regula function again for the next approximation
        regula(&x3, x0, x1, f(x0), f(x1), &itr);

        // Check if the error is within the allowed tolerance
        if (fabs(x3 - x2) < allerr) {
            printf("After %d iterations, root = %6.4f\n", itr, x3);
            printf("\n");
            printf("Shudarsan Poudel");
            return 0;
        }

        // Update x2 for the next iteration
        x2 = x3;

    } while (itr < maxitr);  // Loop until the maximum iterations are reached

    // If the solution does not converge or iterations are insufficient
    printf("Solution does not converge or iterations not sufficient:\n");
    return 1;
}
