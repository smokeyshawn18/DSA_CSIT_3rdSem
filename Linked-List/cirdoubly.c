#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBegin(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Insert at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Insert at random position
void insertAtRandom(int data, int position) {
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (head == NULL && position == 1) {
        head = newNode;
        head->next = head;
        head->prev = head;
        printf("Node inserted successfully!\n");
        return;
    }
    
    struct Node* temp = head;
    int count = 1;
    
    do {
        if (count == position - 1) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            if (position == 1) head = newNode;
            printf("Node inserted successfully!\n");
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);
    
    printf("Position exceeds list length!\n");
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        struct Node* temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
    printf("Node deleted successfully!\n");
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        struct Node* secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        free(last);
    }
    printf("Node deleted successfully!\n");
}

// Delete at random position
void deleteAtRandom(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }
    
    if (position == 1) {
        deleteBegin();
        return;
    }
    
    struct Node* temp = head;
    int count = 1;
    
    do {
        if (count == position - 1) {
            struct Node* toDelete = temp->next;
            if (toDelete == head) {
                printf("Position exceeds list length!\n");
                return;
            }
            temp->next = toDelete->next;
            toDelete->next->prev = temp;
            free(toDelete);
            printf("Node deleted successfully!\n");
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);
    
    printf("Position exceeds list length!\n");
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position;
    printf("Shudarsan Paudel \n");
    
    while (1) {
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBegin(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtRandom(data, position);
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtRandom(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}