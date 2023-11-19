#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int number;
    char name[50];
    char firstName[50];
    char birthDate[20];
    char gender;
};

// Function to input data and create "Etudiant.txt" file
void createEtudiantFile(int numStudents) {
    FILE *file;
    struct Student student;

    file = fopen("Etudiant.txt", "w");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Input data and write to file
    for (int i = 0; i < numStudents; i++) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Number: ");
        scanf("%d", &student.number);
        printf("Name: ");
        scanf("%s", student.name);
        printf("First Name: ");
        scanf("%s", student.firstName);
        printf("Birth Date: ");
        scanf("%s", student.birthDate);
        printf("Gender (M/F): ");
        scanf(" %c", &student.gender);

        fprintf(file, "%d %s %s %s %c\n", student.number, student.name, student.firstName, student.birthDate, student.gender);
    }

    // Close the file
    fclose(file);
}

// Function to separate "Etudiant.txt" into "feminin.txt" and "masculin.txt"
void separateGenderFiles() {
    FILE *etudiantFile, *femininFile, *masculinFile;
    struct Student student;

    etudiantFile = fopen("Etudiant.txt", "r");
    femininFile = fopen("feminin.txt", "w");
    masculinFile = fopen("masculin.txt", "w");

    // Check if files are opened successfully
    if (etudiantFile == NULL || femininFile == NULL || masculinFile == NULL) {
        printf("Error opening files\n");
        return;
    }

    // Read data from "Etudiant.txt" and write to corresponding files
    while (fscanf(etudiantFile, "%d %s %s %s %c", &student.number, student.name, student.firstName, student.birthDate, &student.gender) != EOF) {
        if (student.gender == 'F') {
            fprintf(femininFile, "%d %s %s %s %c\n", student.number, student.name, student.firstName, student.birthDate, student.gender);
        } else if (student.gender == 'M') {
            fprintf(masculinFile, "%d %s %s %s %c\n", student.number, student.name, student.firstName, student.birthDate, student.gender);
        }
    }

    // Close all files
    fclose(etudiantFile);
    fclose(femininFile);
    fclose(masculinFile);
}

// Function to display the youngest student and the youngest studentess
void displayYoungestStudents() {
    FILE *etudiantFile;
    struct Student student, youngestMale, youngestFemale;

    etudiantFile = fopen("Etudiant.txt", "r");

    // Check if file is opened successfully
    if (etudiantFile == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Initialize variables to store the youngest male and female students
    youngestMale.number = youngestFemale.number = -1;

    // Read data from "Etudiant.txt" and find the youngest male and female students
    while (fscanf(etudiantFile, "%d %s %s %s %c", &student.number, student.name, student.firstName, student.birthDate, &student.gender) != EOF) {
        if (student.gender == 'F' && (youngestFemale.number == -1 || student.number < youngestFemale.number)) {
            youngestFemale = student;
        } else if (student.gender == 'M' && (youngestMale.number == -1 || student.number < youngestMale.number)) {
            youngestMale = student;
        }
    }

    // Close the file
    fclose(etudiantFile);

    // Display the youngest male and female students
    printf("Youngest Male Student:\n");
    printf("Number: %d\nName: %s %s\nBirth Date: %s\n", youngestMale.number, youngestMale.name, youngestMale.firstName, youngestMale.birthDate);

    printf("\nYoungest Female Student:\n");
    printf("Number: %d\nName: %s %s\nBirth Date: %s\n", youngestFemale.number, youngestFemale.name, youngestFemale.firstName, youngestFemale.birthDate);
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    createEtudiantFile(numStudents);
    separateGenderFiles();
    displayYoungestStudents();

    return 0;
}
