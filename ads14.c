#include <stdio.h>

// Function to calculate the length of a string
int stringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to check if two strings are equal in length
int areStringsEqualInLength(char* str1, char* str2) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);

    return len1 == len2;
}

int main() {
    char str1[100], str2[100];

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

    // Check if the strings are equal in length and display the result
    if (areStringsEqualInLength(str1, str2)) {
        printf("The two strings are equal in length.\n");
    } else {
        printf("The two strings are not equal in length.\n");
    }

    return 0;
}