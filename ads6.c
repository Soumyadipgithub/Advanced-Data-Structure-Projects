#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Stack structure for non-recursive traversal
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;

    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    struct Node* popped = temp->data;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Iterative in-order traversal
void iterativeInorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    struct Node* current = root;

    while (current || !isEmpty(stack)) {
        while (current) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }

    free(stack);
}

// Iterative pre-order traversal
void iterativePreorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(stack);
        printf("%d ", current->data);

        if (current->right)
            push(stack, current->right);
        if (current->left)
            push(stack, current->left);
    }

    free(stack);
}

// Iterative post-order traversal
void iterativePostorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* current = pop(stack1);
        push(stack2, current);

        if (current->left)
            push(stack1, current->left);
        if (current->right)
            push(stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        struct Node* current = pop(stack2);
        printf("%d ", current->data);
    }

    free(stack1);
    free(stack2);
}

// Function to insert a node in the binary tree according to BST rules
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Iterative In-order traversal: ");
    iterativeInorder(root);
    printf("\n");

    printf("Iterative Pre-order traversal: ");
    iterativePreorder(root);
    printf("\n");

    printf("Iterative Post-order traversal: ");
    iterativePostorder(root);
    printf("\n");

    return 0;
}
