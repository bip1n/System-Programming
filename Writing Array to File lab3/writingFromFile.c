/* Write a program that opens an existing file numbers.txt created in previous program to read an array stored in it and display to screen*/

#include <stdio.h>
int main(){
    int arr;
    FILE *file;
    file = fopen("numbers.txt","r");
    if (file== NULL){
        printf("Error opening file!");
        return -1;
    }
    printf("Numbers read from numbers.txt are: ");
    while (fscanf(file,"%d",&arr)!= EOF){
        printf("%d",arr);
    }
    fclose(file);
    return 0;

}