#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

// Function to implement Simpson's 3/8 Rule
double simpsons_38_rule(double a, double b, int n) {
    double h, sum, x;
    int i;
    
    // Ensure that n is a multiple of 3
    if (n % 3 != 0) {
        printf("Error: n must be a multiple of 3\n");
        return -1;
    }
    
    // Calculate the step size
    h = (b - a) / n;
    
    // Initialize the sum
    sum = f(a) + f(b);  // Add the first and last terms
    
    // Sum the terms with odd indices
    for (i = 1; i < n; i += 3) {
        x = a + i * h;
        sum += 3 * f(x);
    }
    
    // Sum the terms with even indices
    for (i = 2; i < n - 1; i += 3) {
        x = a + i * h;
        sum += 3 * f(x);
    }
    
    // Multiply by 3h/8 to complete the approximation
    return (3 * h / 8) * sum;
}

int main() {
    double a, b, result;
    int n;
    printf("\nShudarsan Poudel\n");
    // Input: lower limit, upper limit, and number of subdivisions
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    
    printf("Enter the number of subdivisions (n, must be a multiple of 3): ");
    scanf("%d", &n);
    
    // Call Simpson's 3/8 Rule function
    result = simpsons_38_rule(a, b, n);
    
    if (result != -1) {
        printf("The approximate integral is: %.6lf\n", result);
    }
    
    return 0;
}
