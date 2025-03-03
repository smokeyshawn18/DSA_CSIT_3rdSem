#include <stdio.h>

// Function to swap two integers (assuming pass-by-value for simplicity)
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Shell Sort implementation
void shellSort(int a[], int size) {
    int h, j, i;  // h is gap, j is outer iterator, i is inner iterator
    
    // Start with large gap and reduce it
    for (h = size/2; h >= 1; h = h/2) {
        // Perform insertion sort for elements separated by gap h
        for (j = h; j < size; j++) {
            // Compare elements with gap h
            for (i = j - h; i >= 0; i = i - h) {
                // If element at i+h is smaller than element at i, swap them
                if (a[i + h] < a[i]) {  // Corrected from original code
                    swap(&a[i + h], &a[i]);
                } else {
                    // If no swap needed, break as this subarray is sorted
                    break;
                }
            }
        }
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the implementation
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    shellSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}