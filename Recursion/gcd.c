#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0) // Base case: when remainder becomes 0
        return a;
    else
        return gcd(b, a % b); // Recursive case: call gcd with (b, remainder)
}

int main() {
    int num1, num2;
    printf("Shudarsan Paudel \n");
    printf("\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}
