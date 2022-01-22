//This program will read a positive integer and print all the positive 
//integers < n divisible by 3 or 5 in ascending order
//Chloe Toh
//z5362296

#include <stdio.h>

int main(void) {
    
    //Declare the integer variables
    int counter;
    int number;
    
    //Ask the user for input and store input
    printf("Enter number: ");
    scanf("%d", &number);
    //Set a counter with minimum value
    counter = 1;
    //Loop while a positive integer 
    while (counter < number) {
        //Print all integers divisible by 3 or 5 
        if (counter % 3 == 0 || counter % 5 == 0) {
            printf("%d\n", counter);
        }
        //Increase the counter value by one 
        counter++;
        
    }
    return 0;
}
