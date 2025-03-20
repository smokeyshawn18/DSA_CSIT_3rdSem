#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
  
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Track if any swap happens
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Swap if elements are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Mark swap
            }
        }
        
        // If no swaps occurred, the array is already sorted
        if (swapped == 0)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 24, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Shudarsan Paudel \n");
    printf("\n");
    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
