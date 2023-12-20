/* Create a structure named employee having members: empName, age and salary. Use this structure to read name, age and salary of employee and write entered information to a file */


#include <stdio.h>

struct employee {
    char empName[50];
    int age;
    float salary;
};

int main() {
    struct employee emp;

    FILE *file;
    file = fopen("employee_info.txt", "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    //Taking input the employee information
    printf("Enter employee name: ");
    scanf("%s", emp.empName);
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    // Write employee information to the file
    fprintf(file, "Employee Name: %s\n", emp.empName);
    fprintf(file, "Employee Age: %d\n", emp.age);
    fprintf(file, "Employee Salary: %.2f\n", emp.salary);

    printf("Employee information written to file 'employee_info.txt' successfully.\n");

    fclose(file);
    return 0;
}