#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to insert element
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove element
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

// Function to get front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to print all elements
void print() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

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
                print();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
