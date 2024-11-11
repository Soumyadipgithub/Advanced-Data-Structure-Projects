#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given data value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST iteratively
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    
    // If the tree is empty, make the new node the root
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    
    struct Node* current = *root;
    struct Node* parent = NULL;
    
    // Traverse the tree to find the correct place for the new node
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // Insert the new node as a left or right child of the parent node
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function to search a node in the BST iteratively
struct Node* search(struct Node* root, int data) {
    struct Node* current = root;
    
    while (current != NULL) {
        if (data == current->data) {
            return current;  // Node found
        } else if (data < current->data) {
            current = current->left;  // Search left subtree
        } else {
            current = current->right;  // Search right subtree
        }
    }
    
    return NULL;  // Node not found
}

// Function to perform an inorder traversal of the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to demonstrate the usage
int main() {
    struct Node* root = NULL;  // Initialize the tree as empty
    int n, value, searchValue;

    // Ask the user how many values they want to insert into the BST
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Insert values into the BST
    printf("Enter %d values to insert into the BST:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insert(&root, value);
    }

    // Perform an inorder traversal to show the BST
    printf("\nInorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    // Ask the user for a value to search in the BST
    printf("Enter a value to search in the BST: ");
    scanf("%d", &searchValue);
    
    // Search for the value in the BST
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Node with value %d found in the BST.\n", searchValue);
    } else {
        printf("Node with value %d not found in the BST.\n", searchValue);
    }
    
    return 0;
}