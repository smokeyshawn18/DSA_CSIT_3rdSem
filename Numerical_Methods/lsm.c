#include <stdio.h>

int main() {
    int n, i;
    float sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;
    float a, b;


    printf("Shudarsan Poudel\n");
    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    // Input the data points (x and y values)
    printf("Enter the values of x and y (x y):\n");
    for (i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Calculate the necessary sums
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    // Calculate the slope (a) and the intercept (b)
    a = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    b = (sum_y - a * sum_x) / n;

    // Output the results
    printf("\nThe equation of the best-fitting line is: y = %.2fx + %.2f\n", a, b);

    return 0;
}
