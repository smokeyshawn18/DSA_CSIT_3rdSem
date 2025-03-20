#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("\nInserted %d at the beginning.\n", value);
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("\nInserted %d at the end.\n", value);
}

// Function to insert at a random position
void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("\nInvalid position!\n");
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("\nInserted %d at position %d.\n", value, position);
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }
    
    printf("\nDeleted %d from beginning.\n", temp->data);
    free(temp);
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    
    if (temp->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    
    printf("\nDeleted %d from end.\n", temp->data);
    free(temp);
}

// Function to delete from a random position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("\nInvalid position!\n");
        return;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    printf("\nDeleted %d from position %d.\n", temp->data, position);
    free(temp);
}

// Function to display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    
    printf("\nDoubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu-driven approach
int main() {
    int choice, value, position;
    printf("Shudarsan Paudel \n");
    
    while (1) {
        printf("\nDoubly Linked List Operations:");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
                
            case 2:
                printf("\nEnter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
                
            case 3:
                printf("\nEnter value: ");
                scanf("%d", &value);
                printf("\nEnter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
                
            case 4:
                deleteFromBeginning();
                break;
                
            case 5:
                deleteFromEnd();
                break;
                
            case 6:
                printf("\nEnter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
                
            case 7:
                display();
                break;
                
            case 8:
                printf("\nExiting...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}