#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    double num, sum = 0.0;
    int count = 0;

    // Get file name from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Calculate the sum and count of numbers in the file
    while (fscanf(file, "%lf", &num) == 1) {
        sum += num;
        count++;
    }

    // Close the file
    fclose(file);

    // Calculate and display the average
    if (count > 0) {
        double average = sum / count;
        printf("Average of numbers in the file: %.2lf\n", average);
    } else {
        printf("No numbers found in the file.\n");
    }

    return 0;
}
