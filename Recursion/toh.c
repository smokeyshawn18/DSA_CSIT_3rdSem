#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Shudarsan Paudel \n");
    printf("\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number of disks\n");
        return 1;
    }

    printf("The steps to solve the Tower of Hanoi with %d disks are:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}