//Program that converts typed digits into word form
//Chloe Toh 26/02/2021
//z5362296

#include <stdio.h>

int main(void) {
    
    //declaring a variable
    int number;
    //asking user for integer
    printf("Please enter an integer: ");
    //scanning user's input
    scanf("%d", &number);
    //if statements depending on input 
    if (number < 1) {
        printf("You entered a number less than one.\n");
    } else if (number == 1) {
        printf("You entered one.\n");
    } else if (number == 2) {
        printf("You entered two.\n");
    } else if (number == 3) {
        printf("You entered three.\n");
    } else if (number == 4) {
        printf("You entered four.\n");
    } else if (number == 5) {
        printf("You entered five.\n");
    } else {
        printf("You entered a number greater than five.\n");
    }
    
    return 0;
}
