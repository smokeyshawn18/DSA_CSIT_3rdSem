#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Stack size

// Stack structure
typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Functions
void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmpty(Stack *s);
void display(Stack *s);

int main() {
    Stack s;
    s.top = -1;  // Initialize stack
    int choice, item;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                item = pop(&s);
                if (item != -1) printf("Popped: %d\n", item);
                break;
            case 3:
                item = peek(&s);
                if (item != -1) printf("Top: %d\n", item);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Push function
void push(Stack *s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->top = s->top + 1;  // Increment top
    s->arr[s->top] = item; // Insert item
}

// Pop function
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int item = s->arr[s->top];
    s->top = s->top - 1; // Decrement top
    return item;
}

// Peek function
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Display function
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
