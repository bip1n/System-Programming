/* Write a program that asks user for 10 numbers and store them in an array. Write this array yo file.*/

#include <stdio.h>
int main(){
    int arr[10],n=10;
    FILE *file;
    file = fopen("numbers.txt","w");
    if (file== NULL){
        printf("Error opening file!");
        return -1;
    }
    printf("Enter 10 numbers for the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        fprintf(file, "%d",arr[i]);
    }
    printf("The numbers are successfully inserted in the file.");

}