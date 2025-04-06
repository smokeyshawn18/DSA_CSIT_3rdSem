#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

// Function to implement Simpson's 1/3 Rule
double simpsons_rule(double a, double b, int n) {
    double h, sum, x;
    int i;
    
    // Ensure that n is even
    if (n % 2 != 0) {
        printf("Error: n must be even\n");
        return -1;
    }
    
    // Calculate the step size
    h = (b - a) / n;
    
    // Initialize the sum
    sum = f(a) + f(b);  // Add the first and last terms
    
    // Sum the terms with odd indices
    for (i = 1; i < n; i += 2) {
        x = a + i * h;
        sum += 4 * f(x);
    }
    
    // Sum the terms with even indices
    for (i = 2; i < n - 1; i += 2) {
        x = a + i * h;
        sum += 2 * f(x);
    }
    
    // Multiply by h/3 to complete the approximation
    return (h / 3) * sum;
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
    
    printf("Enter the number of subdivisions (n, must be even): ");
    scanf("%d", &n);
    
    // Call Simpson's Rule function
    result = simpsons_rule(a, b, n);
    
    if (result != -1) {
        printf("The approximate integral is: %.6lf\n", result);
    }
    
    return 0;
}
