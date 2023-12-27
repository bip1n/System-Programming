/* 
Write a program to read records stored in file in program 1
*/


#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define FILENAME "customer_records.txt"

struct Customer {
    char fname[MAX_NAME_LENGTH];
    char lname[MAX_NAME_LENGTH];
    int accNum;
    double accBalance;
};

int main() {
    struct Customer customers[100];
    int numCustomers = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Records read from '%s':\n", FILENAME);
    while (fscanf(file, "%s %s %d %lf",
                  customers[numCustomers].fname,
                  customers[numCustomers].lname,
                  &customers[numCustomers].accNum,
                  &customers[numCustomers].accBalance) != EOF) {
        printf("Name: %s %s\n", customers[numCustomers].fname, customers[numCustomers].lname);
        printf("Account Number: %d\n", customers[numCustomers].accNum);
        printf("Account Balance: %.2lf\n", customers[numCustomers].accBalance);
        printf("---------------------------\n");
        numCustomers++;
    }

    fclose(file);

    return 0;
}
