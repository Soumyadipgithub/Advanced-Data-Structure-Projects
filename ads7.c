#include <stdio.h>
#include <string.h>
#define MAX 100 // Maximum size of the dictionary
#define WORD_SIZE 100 // Maximum size of each value (string)

// Function to sort the dictionary by keys
void sort_dictionary(int keys[], char values[][WORD_SIZE], int size) {
    int i, j, temp_key;
    char temp_value[WORD_SIZE];
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (keys[i] > keys[j]) {
                // Swap keys
                temp_key = keys[i];
                keys[i] = keys[j];
                keys[j] = temp_key;
                // Swap corresponding values
                strcpy(temp_value, values[i]);
                strcpy(values[i], values[j]);
                strcpy(values[j], temp_value);
            }
        }
    }
}

// Function to display the dictionary
void display_dictionary(int keys[], char values[][WORD_SIZE], int size) {
    int i;
    printf("\nCurrent Dictionary:\n");
    for (i = 0; i < size; i++) {
        printf("Key: %d, Value: %s\n", keys[i], values[i]);
    }
}

// Function to search for a key in the dictionary
int search_key(int keys[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (keys[i] == key) {
            return i; // Return the index of the found key
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to insert a key-value pair
int insert(int keys[], char values[][WORD_SIZE], int size, int key, char value[]) {
    if (search_key(keys, size, key) != -1) {
        printf("Error: Key %d already exists. Duplicates are not allowed.\n", key);
        return size;
    }
    keys[size] = key;
    strcpy(values[size], value);
    size++;
    sort_dictionary(keys, values, size);
    return size;
}

// Function to delete a key-value pair by key
int delete(int keys[], char values[][WORD_SIZE], int size, int key) {
    int index = search_key(keys, size, key);
    if (index == -1) {
        printf("Error: Key %d not found.\n", key);
        return size;
    }
    // Shift elements to the left to overwrite the deleted element
    for (int i = index; i < size - 1; i++) {
        keys[i] = keys[i + 1];
        strcpy(values[i], values[i + 1]);
    }
    size--;
    printf("Key %d deleted.\n", key);
    return size;
}

// Main program
int main() {
    int size = 0, choice, key;
    char value[WORD_SIZE];
    int keys[MAX]; // Array for keys
    char values[MAX][WORD_SIZE]; // 2D array for storing string values

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Sorted Dictionary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key (integer): ");
                scanf("%d", &key);
                printf("Enter the value (word): ");
                scanf("%s", value); // Use %s to input a string
                size = insert(keys, values, size, key, value);
                break;
            case 2:
                printf("Enter the key to delete (integer): ");
                scanf("%d", &key);
                size = delete(keys, values, size, key);
                break;
            case 3:
                printf("Enter the key to search (integer): ");
                scanf("%d", &key);
                int index = search_key(keys, size, key);
                if (index != -1) {
                    printf("Key: %d, Value: %s\n", keys[index], values[index]);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 4:
                display_dictionary(keys, values, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
