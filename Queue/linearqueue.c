#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size of the queue

// Structure for Queue
typedef struct {
    int arr[MAX];  // Queue array
    int front, rear;  // Pointers for queue operations
} Queue;

// Function prototypes
void initQueue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
void enqueue(Queue* q, int item);
int dequeue(Queue* q);
int peek(Queue* q);
void display(Queue* q);

int main() {
    Queue q;  // Declare queue
    initQueue(&q);  // Initialize queue

    int choice, item;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1)
                    printf("\nDequeued item: %d\n", item);
                break;
            case 3:
                printf("\nFront item: %d\n", peek(&q));
                break;
            case 4:
                display(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

// Initialize queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1);
}

// Check if queue is full
int isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Enqueue (Insert) element
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("\nQueue Overflow! Cannot insert.\n");
        return;
    }
    if (isEmpty(q))  // First element condition
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = item;
    printf("\nInserted %d into queue.\n", item);
}

// Dequeue (Remove) element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue Underflow! No elements to remove.\n");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front == q->rear)  // Last element removed
        initQueue(q);  // Reset queue
    else
        q->front++;
    return item;
}

// Get front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

// Display queue elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}
