//A program that will read a integer and print out a hollow triangle shape 
//made up of asterisks 
//Chloe Toh
//z5362296

#include <stdio.h>

int main (void) {
    //Declare an input variable for the size of the shape
    int size;
    //Ask for input and store as variable
    printf("Enter size: ");
    scanf("%d", &size);
    //Double while loop for rows and columns
    int row = 1; 
    while (row <= size) {
        int column = 1;
        while (column <= size) {
            //Insert conditions for the asterisks 
            if (row == column || row == size || column == 1) {
                printf("*");
            } else { 
                printf(" ");
            }
            column++;
        }
        printf("\n");
        row++;
    }
    return 0;
}
