#include <stdio.h>

int main() {
    int n, i, j;
    float x, l, v = 0;
    float ax[10], fx[10], L[10];

    // Input the number of data points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input the value of x where interpolation is required
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &x);

    // Input the x and fx values
    for (i = 0; i < n; i++) {
        printf("Enter the value of x and f(x) at i=%d: ", i);
        scanf("%f%f", &ax[i], &fx[i]);
    }

    // Calculate the Lagrange basis polynomials L[i](x)
    for (i = 0; i < n; i++) {
        l = 1.0;
        for (j = 0; j < n; j++) {
            if (j != i) {
                l *= (x - ax[j]) / (ax[i] - ax[j]);
            }
        }
        L[i] = l;  // Store the value of the Lagrange basis polynomial
    }

    // Compute the interpolated value
    for (i = 0; i < n; i++) {
        v += fx[i] * L[i];
    }

    // Output the result
    printf("Interpolated value at x = %.2f is: %.5f\n", x, v);
    printf("\nShudarsan Poudel\n");

    return 0;
}
