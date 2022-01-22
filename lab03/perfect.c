//This program will print all the factors, the sum of the factors of an 
//input and also determine if the input is a perfect number
//Chloe Toh
//z5362296

#include <stdio.h>

int main(void) {
    //Declare the variables 
    int integer;
    int counter;
    int sum;
    //Read the user's input and store it
    printf("Enter number: ");
    scanf("%d", &integer); 
    //Set the counter to a minimum value
    counter = 1;
    sum = 0;
    printf("The factors of %d are:\n", integer);
    //Create a loop that runs for all integers smaller than the input 
    while (counter <= integer) {
        //Print all the factors of the input 
        if (integer % counter == 0) {
            printf("%d\n", counter); 
            //Sum the factors together
            sum = sum + counter; 
        }
        counter++;
    }
    printf("Sum of factors = %d\n", sum);
    //Check if it is a perfect number 
    if (sum-integer == integer) {
        printf("%d is a perfect number\n", integer);
    } else { 
        printf("%d is not a perfect number\n", integer); 
    }
    return 0;
}

    
