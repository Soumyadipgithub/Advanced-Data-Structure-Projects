#include <stdio.h>

// Function to calculate the length of a string
int stringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void concatenateStrings(char* destination, char* source) {
    int destLength = stringLength(destination);
    int i = 0;

    // Append each character of source to destination
    while (source[i] != '\0') {
        destination[destLength + i] = source[i];
        i++;
    }

    // Null-terminate the resulting string
    destination[destLength + i] = '\0';
}

int main() {
    char str1[200], str2[100];

    // Get input for the first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    // Remove newline character if present
    if (str1[stringLength(str1) - 1] == '\n') {
        str1[stringLength(str1) - 1] = '\0';
    }

    // Get input for the second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline character if present
    if (str2[stringLength(str2) - 1] == '\n') {
        str2[stringLength(str2) - 1] = '\0';
    }

    // Concatenate str2 to str1
    concatenateStrings(str1, str2);

    // Display the concatenated result
    printf("Concatenated string: %s\n", str1);

    return 0;
}