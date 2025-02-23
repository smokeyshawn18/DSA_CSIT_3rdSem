#include <stdio.h>

// Define the maximum size of the queue
#define MAX_SIZE 5

// Declare the queue array and front, rear variables
int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to enqueue (insert) an element
void enqueue(int data) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert %d\n", data);
        return;
    }
    if (front == -1) { // If inserting the first element
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("\nElement %d inserted into the queue.\n", data);
}

// Function to dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow! No elements to remove.\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) { // If only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("\nDequeued element: %d\n", data);
    return data;
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

// Main function with menu-driven interface
int main() {
    int choice, value;
    while (1) {
        printf("\n====== Circular Queue Menu ======\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
