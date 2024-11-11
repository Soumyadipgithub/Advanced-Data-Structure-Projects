#include <stdio.h>

int stringLength(char* str) {
    int length = 0;

    // Loop through each character in the string until we reach the null terminator
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[100];

    // Get input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    if (str[stringLength(str) - 1] == '\n') {
        str[stringLength(str) - 1] = '\0';
    }

    // Calculate and display the length of the string
    int length = stringLength(str);
    printf("The length of the string is: %d\n", length);

    return 0;
}