#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFilename[100], outputFilename[] = "palindrome.txt";
    char word[50];
    int palindromeCount = 0;

    // Get input file name from user
    printf("Enter the input filename: ");
    scanf("%s", inputFilename);

    inputFile = fopen(inputFilename, "r");
    outputFile = fopen(outputFilename, "w");

    // Check if files are opened successfully
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    // Find palindromes in the input file and write them to the output file
    while (fscanf(inputFile, "%s", word) == 1) {
        if (isPalindrome(word)) {
            fprintf(outputFile, "%s\n", word);
            palindromeCount++;
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    // Display the number of palindromes
    printf("Number of palindromes: %d\n", palindromeCount);

    return 0;
}
