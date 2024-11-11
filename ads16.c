#include <stdio.h>

// Function to compare two strings character by character
int areStringsIdentical(char* str1, char* str2) {
    int i = 0;

    // Compare each character of both strings
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; // Strings are not identical
        }
        i++;
    }

    // Check if both strings ended simultaneously
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1; // Strings are identical
    } else {
        return 0; // One string is longer than the other
    }
}

int main() {
    char str1[100], str2[100];

    // Get input for the first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    // Remove newline character if present
    int len = 0;
    while (str1[len] != '\0') {
        if (str1[len] == '\n') {
            str1[len] = '\0';
        }
        len++;
    }

    // Get input for the second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline character if present
    len = 0;
    while (str2[len] != '\0') {
        if (str2[len] == '\n') {
            str2[len] = '\0';
        }
        len++;
    }

    // Compare the two strings and display the result
    if (areStringsIdentical(str1, str2)) {
        printf("The two strings are identical.\n");
    } else {
        printf("The two strings are not identical.\n");
    }

    return 0;
}