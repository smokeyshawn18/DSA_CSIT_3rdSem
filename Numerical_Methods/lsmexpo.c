#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;
    float b, A, a;

    printf("\nShudarsan Poudel\n");

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n], Y[n];

    // Input the data points (x and y values)
    printf("Enter the values of x and y (x y):\n");
    for (i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
        Y[i] = log(y[i]); // Taking the natural log of y
    }

    // Calculate the necessary sums
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += Y[i];
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * Y[i];
    }

    // Calculate the slope (b) and intercept (A)
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    A = (sum_y - b * sum_x) / n;

    // Calculate a from A
    a = exp(A);

    // Output the results
    printf("\nThe equation of the best-fitting exponential curve is: y = %.5fe^(%.5fx)\n", a, b);

    return 0;
}
