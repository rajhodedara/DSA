#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end
struct Node* insertTerm(struct Node* head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display a polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            result = insertTerm(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            result = insertTerm(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {
            // powers are same, so add coefficients
            int sum = poly1->coeff + poly2->coeff;
            result = insertTerm(result, sum, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Copy remaining terms from either polynomial
    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        poly1 = insertTerm(poly1, coeff, pow);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        poly2 = insertTerm(poly2, coeff, pow);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    display(sum);

    return 0;
}
