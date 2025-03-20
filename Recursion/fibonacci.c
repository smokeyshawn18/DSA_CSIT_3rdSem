#include <stdio.h>
#include <conio.h>

void main () {
    int n,i;
    printf("Shudarsan Paudel \n");
    printf("\n");
    int fibonacci(int);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("nth Fibonacci term is: \n");
    printf("%d", fibonacci(n));
    getch();
}

int fibonacci(int k){
    if(k == 1 || k == 2){
        return 1;
    } else {
        return fibonacci(k - 1) + fibonacci(k - 2);
    }
}