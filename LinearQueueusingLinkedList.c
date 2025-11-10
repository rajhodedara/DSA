#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert element (Enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Queue Overflow.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  // if queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

// Function to delete element (Dequeue)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;

    if (front == NULL)  // if queue becomes empty
        rear = NULL;

    free(temp);
}

// Function to view the front element (Peek)
void peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Function to print all elements
void printQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function with switch menu
int main() {
    int choice, value;

    while (1) {
        printf("\n---- LINEAR QUEUE MENU ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to Enqueue: ");
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
                printQueue();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
