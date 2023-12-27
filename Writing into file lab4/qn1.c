         /* Define a structure named Customer that has fname, lname, accNum and accBalance as its members. Assume appropriate type and size of members.
 Use this structure to read account information of multiple persons and save records to a file. Your program should read records until user enters 'stop' for fname.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50
#define FILENAME "customer_records.txt"

struct Customer {
    char fname[MAX_NAME_LENGTH];
    char lname[MAX_NAME_LENGTH];
    int accNum;
    double accBalance;
};

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    char stop[] = "stop";

    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter customer information (fname, lname, accNum, accBalance):\n");
    while (numCustomers < MAX_CUSTOMERS) {
        printf("Enter first name (or 'stop' to end): ");
        scanf("%s", customers[numCustomers].fname);

        // Check if the user wants to stop entering data
        if (strcmp(customers[numCustomers].fname, stop) == 0) {
            break;
        }

        printf("Enter last name: ");
        scanf("%s", customers[numCustomers].lname);

        printf("Enter account number: ");
        scanf("%d", &customers[numCustomers].accNum);

        printf("Enter account balance: ");
        scanf("%lf", &customers[numCustomers].accBalance);

        numCustomers++;
    }

    for (int i = 0; i < numCustomers; i++) {
        fprintf(file, "%s %s %d %.2lf\n",
                customers[i].fname,
                customers[i].lname,
                customers[i].accNum,
                customers[i].accBalance);
    }

    fclose(file);

    printf("Records saved to '%s'.\n", FILENAME);

    return 0;
}



