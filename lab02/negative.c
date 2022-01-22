//Program that prints 'Don't be so negative' if the user inputs a negative number
//Chloe Toh 26/02/2021 
//z5362296 

#include<stdio.h>

int main(void) {

    //declaring a variable
    int number;
    //scanning user's input 
    scanf ("%d", &number);
    //determining if it is positive, negative or zero
    if (number > 0) {
        printf ("You have entered a positive number.\n");
    } else if (number < 0) {
        printf ("Don't be so negative!\n");
    } else {
        printf ("You have entered zero.\n");
    }
    
    return 0;
}
