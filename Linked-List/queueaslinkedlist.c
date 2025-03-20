#include <stdio.h>
#include <stdlib.h>

// Structure for queue node
struct Node {
    int data;
    struct Node* next;
};

// Global front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to enqueue (add element to rear)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (rear == NULL) {
        // If queue is empty, set both front and rear to new node
        front = rear = newNode;
    } else {
        // Add new node at rear and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue (remove element from front)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = front;
    printf("%d dequeued from queue\n", front->data);
    front = front->next;
    
    if (front == NULL) {
        // If queue becomes empty, reset rear
        rear = NULL;
    }
    free(temp);
}

// Function to peek front element
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", front->data);
}

// Function to display queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice, value;
    printf("Shudarsan Paudel \n");
    
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                // Free remaining nodes before exit
                while (front != NULL) {
                    struct Node* temp = front;
                    front = front->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}