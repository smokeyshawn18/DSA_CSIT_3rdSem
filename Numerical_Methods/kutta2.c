#include <stdio.h>

// Function for the second equation (dy2/dx = f(x, y1, y2))
double f(double x, double y1, double y2) {
    return -y1;  // Example: dy2/dx = -y1
}

// Runge-Kutta method to solve second-order ODE
void rungeKutta(double x0, double y10, double y20, double x, double h, int n) {
    double k1, k2, k3, k4, k5, k6, k7, k8;
    double y1 = y10, y2 = y20;
    
    printf("x0 = %.4lf, y1 = %.4lf, y2 = %.4lf\n", x0, y1, y2);

    // Runge-Kutta iterations
    for (int i = 1; i <= n; i++) {
        // Calculate k1, k2, k3, k4 for y1 (dy1/dx)
        k1 = h * y2;
        k2 = h * (y2 + 0.5 * k1);
        k3 = h * (y2 + 0.5 * k2);
        k4 = h * (y2 + k3);

        // Calculate k1, k2, k3, k4 for y2 (dy2/dx = f(x, y1, y2))
        k5 = h * f(x0, y1, y2);
        k6 = h * f(x0 + 0.5 * h, y1 + 0.5 * k1, y2 + 0.5 * k5);
        k7 = h * f(x0 + 0.5 * h, y1 + 0.5 * k2, y2 + 0.5 * k6);
        k8 = h * f(x0 + h, y1 + k3, y2 + k7);

        // Update y1 and y2
        y1 = y1 + (k1 + 2*k2 + 2*k3 + k4) / 6;
        y2 = y2 + (k5 + 2*k6 + 2*k7 + k8) / 6;

        // Increment x0 by step size h
        x0 = x0 + h;

        printf("At x = %.4lf, y1 = %.4lf, y2 = %.4lf\n", x0, y1, y2);
    }
}

int main() {
    double x0, y10, y20, x, h;
    int n;
printf("Shudarsan Poudel\n");
    // Input the initial conditions and parameters
    printf("Enter the initial value of x0: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y1 (y0): ");
    scanf("%lf", &y10);
    printf("Enter the initial value of y2 (dy0/dx): ");
    scanf("%lf", &y20);
    printf("Enter the value of x where you want to find the solution: ");
    scanf("%lf", &x);
    printf("Enter the step size h: ");
    scanf("%lf", &h);

    // Calculate the number of steps (n)
    n = (int)((x - x0) / h);

    // Call Runge-Kutta method
    rungeKutta(x0, y10, y20, x, h, n);

    return 0;
}
