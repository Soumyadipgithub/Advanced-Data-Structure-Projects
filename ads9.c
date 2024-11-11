#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 31 // Define a prime number for multiplication

// Function to compute hash value from input details
int computeHashValue(char* firstName, char* lastName, char* phoneNumber) {
    int hashValue = 0;

    // Get first 3 characters of first name and convert to ASCII
    for (int i = 0; i < 3; i++) {
        hashValue += firstName[i] * PRIME;
    }

    // Get first 3 characters of last name and convert to ASCII
    for (int i = 0; i < 3; i++) {
        hashValue += lastName[i] * PRIME;
    }

    // Get first 3 digits of phone number and convert to integer
    for (int i = 0; i < 3; i++) {
        hashValue += (phoneNumber[i] - '0');
    }

    return hashValue;
}

int main() {
    char firstName[50], lastName[50], phoneNumber[15];
    int range;

    // Get input from user
    printf("Enter first name: ");
    scanf("%s", firstName);
    printf("Enter last name: ");
    scanf("%s", lastName);
    printf("Enter phone number: ");
    scanf("%s", phoneNumber);

    // Ensure the inputs have at least 3 characters each
    if (strlen(firstName) < 3 || strlen(lastName) < 3 || strlen(phoneNumber) < 3) {
        printf("First name, last name, and phone number must have at least 3 characters.\n");
        return 1;
    }

    // Compute the hash value
    int hashValue = computeHashValue(firstName, lastName, phoneNumber);
    printf("Computed hash value (before modulus): %d\n", hashValue);

    // Get range from user
    printf("Enter the range for the hash table: ");
    scanf("%d", &range);

    // Calculate the final hash value by taking modulus with range
    int finalHashValue = hashValue % range;
    printf("Final hash value (after modulus with range): %d\n", finalHashValue);

    return 0;
}