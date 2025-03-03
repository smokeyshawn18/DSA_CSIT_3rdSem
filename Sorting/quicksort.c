#include <stdio.h>

// Swap function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSort
int partition(int arr[], int left, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = left - 1; // Pointer for the smaller element

    for (int j = left; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]); // Swap elements
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return (i + 1);
}

// QuickSort function
void QuickSort(int arr[], int left, int high) {
    if (left < high) {
        int pl = partition(arr, left, high); // Get pivot position
        QuickSort(arr, left, pl - 1); // Sort left subarray
        QuickSort(arr, pl + 1, high); // Sort right subarray
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    QuickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
