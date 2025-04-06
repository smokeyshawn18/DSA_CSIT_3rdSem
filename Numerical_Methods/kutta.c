#include <stdio.h>

// Function prototype for the derivative of y(x), dy/dx = f(x, y)
double f(double x, double y);

// Function to implement the Runge-Kutta method of 4th order
void rungeKutta(double x0, double y0, double x, double h, int n) {
    double k1, k2, k3, k4, y;
    y = y0;
    printf("x0 = %.4lf, y0 = %.4lf\n", x0, y0);
    for (int i = 1; i <= n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);

        // Calculate next value of y
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;

        // Increment x0 by step size h
        x0 = x0 + h;

        printf("At x = %.4lf, y = %.4lf\n", x0, y);
    }
}

// Example function f(x, y) = y - x^2 + 1 (dy/dx = y - x^2 + 1)
double f(double x, double y) {
    return y - x * x + 1;
}

int main() {
    double x0, y0, x, h;
    int n;

    printf("Shudarsan Poudel\n");
    // Input the initial conditions and parameters
    printf("Enter the initial value of x0: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y0: ");
    scanf("%lf", &y0);
    printf("Enter the value of x where you want to find the solution: ");
    scanf("%lf", &x);
    printf("Enter the step size h: ");
    scanf("%lf", &h);

    // Calculate the number of steps (n)
    n = (int)((x - x0) / h);

    // Call Runge-Kutta method
    rungeKutta(x0, y0, x, h, n);

    return 0;
}
