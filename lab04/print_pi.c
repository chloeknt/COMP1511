// Prints the first n digits of pi, where n is specified 
// Chloe Toh 12/03/2021
// z5362296

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    //Declare and initialise an array of up to ten digits of pi
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    //Declare a variable for the number of digits
    int digits; 
    //Ask the user for the number of digits 
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digits);
    //Loop through the number of digits 
    int i = 0;
    while (i < digits) {
        printf("%d", pi[i]);
            //Add if condition for the decimal point
            if (i == 0 && digits > 1) {
                printf(".");
            } 
            //Increase the index
            i++;
    }
    printf("\n");
    return 0;
}
