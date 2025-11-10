#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        // If the tree is empty, create a new node
        return createNode(value);
    }

    if (value < root->data) {
        // Insert in the left subtree
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // Insert in the right subtree
        root->right = insert(root->right, value);
    } else {
        // Duplicate values are not allowed in BST
        printf("Value %d already exists in the BST.\n", value);
    }

    return root;
}

// Function to search for a value in the BST
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0; // Value not found
    }

    if (root->data == value) {
        return 1; // Value found
    } else if (value < root->data) {
        // Search in the left subtree
        return search(root->left, value);
    } else {
        // Search in the right subtree
        return search(root->right, value);
    }
}

// In-order traversal to display the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

   while (1) {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display (In-order Traversal)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value)) {
                printf("Value %d found in the BST.\n", value);
            } else {
                printf("Value %d not found in the BST.\n", value);
            }
            break;

        case 3:
            printf("In-order Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;  // simpler than exit(0)

        default:
            printf("Invalid choice. Please try again.\n");
    }
}


    return 0;
}
