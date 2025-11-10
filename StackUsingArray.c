#include <stdio.h>
#define MAX 5   // Define maximum size of the stack

int stack[MAX];
int top = -1;  // Initialize top as -1 (empty stack)

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Function to return top element without removing it
void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Function to print all elements in the stack
void print() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. PRINT\n");
        printf("5. Check if EMPTY\n");
        printf("6. Check if FULL\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
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
                print();
                break;
            case 5:
                if (isEmpty())
                    printf("Stack is Empty.\n");
                else
                    printf("Stack is not Empty.\n");
                break;
            case 6:
                if (isFull())
                    printf("Stack is Full.\n");
                else
                    printf("Stack is not Full.\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
