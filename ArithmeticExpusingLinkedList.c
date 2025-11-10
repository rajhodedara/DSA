#include <stdio.h>
#include <stdlib.h>

// Define structure for each term of polynomial
struct Node {
    int coeff;   // coefficient
    int pow;     // power of x
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term at the end of list
void insertTerm(int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display polynomial
void displayPolynomial() {
    struct Node* temp = head;
    printf("\nPolynomial Expression using Linked List:\n");

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, pow;

    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(coeff, pow);
    }

    displayPolynomial();
    return 0;
}
