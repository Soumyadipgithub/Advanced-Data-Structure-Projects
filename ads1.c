#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the binary tree
struct treeNode {
    int data;
    struct treeNode* leftChild;
    struct treeNode* rightChild;
};

// Inorder traversal (Left, Root, Right)
void inorderTraversal(struct treeNode* currentNode) {
    if (currentNode == NULL) return;
    inorderTraversal(currentNode->leftChild);  // Traverse left subtree
    printf("%d ", currentNode->data);          // Visit the node
    inorderTraversal(currentNode->rightChild); // Traverse right subtree
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(struct treeNode* currentNode) {
    if (currentNode == NULL) return;
    printf("%d ", currentNode->data);          // Visit the node
    preorderTraversal(currentNode->leftChild); // Traverse left subtree
    preorderTraversal(currentNode->rightChild); // Traverse right subtree
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(struct treeNode* currentNode) {
    if (currentNode == NULL) return;
    postorderTraversal(currentNode->leftChild);  // Traverse left subtree
    postorderTraversal(currentNode->rightChild); // Traverse right subtree
    printf("%d ", currentNode->data);            // Visit the node
}

// Function to create a new node
struct treeNode* createNode(int nodeValue) {
    struct treeNode* newNode = malloc(sizeof(struct treeNode)); // Allocate memory for a new node
    newNode->data = nodeValue;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct treeNode* insertNode(struct treeNode* rootNode, int nodeValue) {
    if (rootNode == NULL) {
        return createNode(nodeValue);  // If tree is empty, create a new node
    }

    // Insert node recursively based on value comparison
    if (nodeValue < rootNode->data) {
        rootNode->leftChild = insertNode(rootNode->leftChild, nodeValue);  // Insert in left subtree
    } else {
        rootNode->rightChild = insertNode(rootNode->rightChild, nodeValue); // Insert in right subtree
    }

    return rootNode;
}

int main() {
    struct treeNode* rootNode = NULL;
    int totalNodes, nodeValue;

    // Get the number of nodes from the user
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &totalNodes);

    // Get values for nodes and insert them into the tree
    for (int i = 0; i < totalNodes; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &nodeValue);
        rootNode = insertNode(rootNode, nodeValue);
    }

    // Perform and print tree traversals
    printf("\nTraversal of the constructed binary tree\n");

    printf("Inorder traversal:\n");
    inorderTraversal(rootNode);
    printf("\n");

    printf("Preorder traversal:\n");
    preorderTraversal(rootNode);
    printf("\n");

    printf("Postorder traversal:\n");
    postorderTraversal(rootNode);
    printf("\n");

    return 0;
}
