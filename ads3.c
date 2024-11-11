#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST recursively
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->value) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

// In-order traversal of the BST (left, root, right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// Function to search for a key in the BST recursively
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->value == key) {
        return root;
    }

    if (key < root->value) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, value, searchValue;

    // Input number of nodes to insert
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    // Input values to insert into the BST
    printf("Enter the values to insert into the BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Perform in-order traversal of the BST
    printf("\nIn-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    printf("Enter a value to search in the BST: ");
    scanf("%d", &searchValue);
    struct Node* result = search(root, searchValue);
    if (result != NULL) {
        printf("Found %d in the BST.\n", searchValue);
    } else {
        printf("%d not found in the BST.\n", searchValue);
    }

    return 0;
}
