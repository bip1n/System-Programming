/* Define a structure named student that has name, roll and marks as members. Assume appropriate types and size of members. Use this structure to read and display records of 3 students. Write array of structure to a file and then read its content to display to screen.*/

#include <stdio.h>

// Define the structure for a student
struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct student students[3];
    FILE *file;

    // Input records for 3 students
    printf("Enter details for 3 students:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &students[i].roll);
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }

    // Write array of structures to a file
    file = fopen("students_info.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fwrite(students, sizeof(struct student), 3, file);
    fclose(file);

    // Read content from file and display it on the screen
    file = fopen("students_info.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("\nDetails of students read from file:\n");
    fread(students, sizeof(struct student), 3, file);

    for (int i = 0; i < 3; ++i) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    fclose(file);
    return 0;
}