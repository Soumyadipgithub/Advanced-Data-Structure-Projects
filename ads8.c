#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Define a structure for a key-value pair
struct KeyValuePair {
    int key;
    int value;
};

// Define a structure for the priority queue
struct PriorityQueue {
    struct KeyValuePair items[MAX_SIZE];
    int size;
};

// Function to initialize the priority queue
void initialize(struct PriorityQueue* queue) {
    queue->size = 0;
}

// Function to insert a key-value pair into the priority queue
void insert(struct PriorityQueue* queue, int key, int value) {
    if (queue->size >= MAX_SIZE) {
        printf("Priority Queue is full. Cannot insert.\n");
        return;
    }

    int index = queue->size;
    while (index > 0 && key < queue->items[index - 1].key) {
        queue->items[index] = queue->items[index - 1];
        index--;
    }

    queue->items[index].key = key;
    queue->items[index].value = value;
    queue->size++;

    printf("Key '%d' inserted successfully.\n", key);
}

// Function to remove and return the highest priority key-value pair from the priority queue
struct KeyValuePair extractMin(struct PriorityQueue* queue) {
    struct KeyValuePair minPair;
    minPair.key = -1; // Initialize to a sentinel value

    if (queue->size == 0) {
        printf("Priority Queue is empty. Cannot extract minimum.\n");
        return minPair;
    }

    minPair = queue->items[0];

    // Shift the items to fill the gap left by the extracted item
    for (int i = 1; i < queue->size; i++) {
        queue->items[i - 1] = queue->items[i];
    }

    queue->size--;

    return minPair;
}

// Function to print all key-value pairs in the priority queue
void printPriorityQueue(const struct PriorityQueue* queue) {
    printf("Priority Queue Contents (Sorted by Keys):\n");
    for (int i = 0; i < queue->size; i++) {
        printf("Key: %d, Value: %d\n", queue->items[i].key, queue->items[i].value);
    }
}

int main() {
    struct PriorityQueue queue;
    initialize(&queue);

    int choice, key, value;
    struct KeyValuePair minPair;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Extract Minimum\n");
        printf("3. Print Priority Queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key (integer): ");
                scanf("%d", &key);
                printf("Enter value (integer): ");
                scanf("%d", &value);
                insert(&queue, key, value);
                break;
            case 2:
                minPair = extractMin(&queue);
                if (minPair.key != -1) {
                    printf("Extracted Minimum Key: %d, Value: %d\n", minPair.key, minPair.value);
                }
                break;
            case 3:
                printPriorityQueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
