#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum stack size

// Structure for node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // top pointer
int count = 0; // keeps track of number of elements

// Function to check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to check if stack is full
int isFull() {
    return count == SIZE;
}

// Function to push element
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->next = top;
    top = newNode;
    count++;
    printf("%d pushed to stack.\n", value);
}

// Function to pop element
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
    count--;
}

// Function to view top element
void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to print all elements
void printStack() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements (top to bottom): ");
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
        printf("\n---- STACK MENU ----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Print Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty())
                    printf("Stack is EMPTY.\n");
                else
                    printf("Stack is NOT empty.\n");
                break;
            case 5:
                if (isFull())
                    printf("Stack is FULL.\n");
                else
                    printf("Stack is NOT full.\n");
                break;
            case 6:
                printStack();
                break;
            case 7:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
        