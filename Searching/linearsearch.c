#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int n, key, result;

    printf("Shudarsan Paudel \n");
    printf("\n");
    // Taking input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declaring an array of size n

    // Taking input for array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking input for the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Calling the linear search function
    result = linearSearch(arr, n, key);

    // Checking the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
