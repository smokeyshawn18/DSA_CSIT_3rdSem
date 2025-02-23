#include <stdio.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if (i < n - 1) {  // Only add a comma if it's NOT the last element
            printf(", ");
        }
    }
    printf("\n");
}

// main function

int main(){
    int arr[] = {3,2,6,4,9,22,15};
    int n = sizeof(arr) / sizeof(arr[0]); // array size calculation
    insertionSort(arr, n);
    printf("Sorted Array is: ");
    print(arr, n);
}