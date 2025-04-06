#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (cos(x) + 2 * sin(x) + x * x)

int main() {
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;

    printf("\nEnter initial guesses:\n");
    scanf("%f %f", &x0, &x1);

    printf("Enter tolerable error:\n");
    scanf("%f", &e);

    printf("Enter maximum iterations:\n");
    scanf("%d", &N);
    
    printf("\nStep\t\tx0\t\tx1\t\tf(x0)\t\tf(x1)\t\tx2\n");
    
    do {
        f0 = f(x0);
        f1 = f(x1);

        if (fabs(f1 - f0) < 1e-10) {
            printf("Mathematical Error: Division by zero.\n");
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\t%f\n", step, x0, x1, f0, f1, x2);

        if (fabs(f2) < e) {
            printf("\nRoot is: %f\n", x2);
            printf("\n Shudarsan Poudel");
            
            // Ask if user wants to try finding another root
            char choice;
            printf("\nDo you want to try finding another root? (y/n): ");
            scanf(" %c", &choice);
            
            if (choice == 'y' || choice == 'Y') {
                printf("\nEnter new initial guesses:\n");
                scanf("%f %f", &x0, &x1);
                step = 1;
                printf("\nStep\t\tx0\t\tx1\t\tf(x0)\t\tf(x1)\t\tx2\n");
                continue;
            }
            return 0;
        }

        x0 = x1;
        x1 = x2;
        step++;

        if (step > N) {
            printf("Not Convergent with these initial guesses.\n");
            // Ask if user wants to try different guesses
            char choice;
            printf("\nDo you want to try different initial guesses? (y/n): ");
            scanf(" %c", &choice);
            
            if (choice == 'y' || choice == 'Y') {
                printf("\nEnter new initial guesses:\n");
                scanf("%f %f", &x0, &x1);
                step = 1;
                printf("\nStep\t\tx0\t\tx1\t\tf(x0)\t\tf(x1)\t\tx2\n");
                continue;
            }
            return 0;
        }
    } while(1);
    
    return 0;
}