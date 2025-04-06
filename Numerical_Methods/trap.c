#include <stdio.h>

// Function to calculate the value of the given function at x
float f(float x) {
    // Example function: f(x) = x^2
    return x * x;  // Change this as per the function you want to integrate
}

// Function to implement the Trapezoidal Rule
float trapezoidal(float (*func)(float), float a, float b, int n) {
    float h, sum, x;

    // Step size
    h = (b - a) / n;
    
    // Calculate the sum using the Trapezoidal Rule formula
    sum = (func(a) + func(b)) / 2.0;
    
    // Add the intermediate terms
    for (int i = 1; i < n; i++) {
        x = a + i * h;
        sum += func(x);
    }
    
    // Multiply by the step size (h)
    sum *= h;
    
    return sum;
}

int main() {
    float a, b;
    int n;
    
    printf("\nShudarsan Poudel\n");
    // Input for limits of integration and number of subdivisions
    printf("Enter the limits of integration (a, b): ");
    scanf("%f %f", &a, &b);
    
    printf("Enter the number of subdivisions (n): ");
    scanf("%d", &n);
    
    // Calculate the integral using the Trapezoidal Rule
    float result = trapezoidal(f, a, b, n);
    
    // Output the result
    printf("The approximate integral is: %.6f\n", result);
    
    return 0;
}
