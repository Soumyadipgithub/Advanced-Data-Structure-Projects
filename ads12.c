#include <stdio.h>
#include <string.h>

// Function to count occurrences of the word in the text
int countOccurrences(char* text, char* word) {
    int count = 0;
    int textLen = strlen(text);
    int wordLen = strlen(word);

    // Loop through the text to find the word
    for (int i = 0; i <= textLen - wordLen; i++) {
        // Check if word matches at current position
        if (strncmp(&text[i], word, wordLen) == 0) {
            count++;
            i += wordLen - 1; // Move index to end of current match to avoid overlapping
        }
    }
    return count;
}

int main() {
    char text[1000], word[50];

    // Get the paragraph text input from user
    printf("Enter a paragraph of text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character if present
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // Get the word to search in the text
    printf("Enter the word to search for: ");
    scanf("%s", word);

    // Display the inputted text and word
    printf("\nInputted Text: %s\n", text);
    printf("Word to Search: %s\n", word);

    // Count occurrences of the word in the text
    int occurrences = countOccurrences(text, word);

    // Display the result
    printf("The word '%s' appeared %d time(s) in the text.\n", word, occurrences);

    return 0;
}