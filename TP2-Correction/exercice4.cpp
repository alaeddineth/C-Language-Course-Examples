#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int letterCount[26] = {0};

    // Get file name from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Count the occurrences of each letter in the file
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            letterCount[ch - 'A']++;
        }
    }

    // Close the file
    fclose(file);

    // Display the letter statistics
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, letterCount[i]);
    }

    return 0;
}
