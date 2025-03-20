#include <stdio.h>

// Function to perform binary search (iterative method)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate middle index

        // Check if the key is at mid
        if (arr[mid] == key)
            return mid;

        // If key is smaller, search the left half
        if (arr[mid] > key)
            right = mid - 1;
        else // If key is larger, search the right half
            left = mid + 1;
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, key, result;

    printf("Shudarsan Paudel \n");
    printf("\n");
    // Taking input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input for sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking input for the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Calling the binary search function
    result = binarySearch(arr, 0, n - 1, key);

    // Checking the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
