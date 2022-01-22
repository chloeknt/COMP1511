//A program which will scan instructions until EOF and print the output 
//as specified:
//First number is one, the program prints out the squar of the next number
//First number is two, the program prints out the value of the next 
//number raised to the power of the number after next
//Chloe Toh 12/03/2021
//z5362296

#include <stdio.h>
#include <math.h>

int main(void) {
    //Create array with 3 slots
    int num[3] = {0};
    //Declare and initialise a variable for looping condition 
    int keep_looping = 1;
    //Create a loop for the question and output
    while (keep_looping == 1) {
        //Ask for input
        printf("Enter instruction: ");
        //Scan the first input
        int result = scanf("%d", &num[0]); 
        //Set a condition for if ctrl D is entered 
        if (result == EOF) {
            keep_looping = 0;
            //Set conditions for if the first number is 1 or 2 
        } else if (num[0] == 1 && num[0]) {
            scanf("%d", &num[1]);
            //If number is 1, return the square of the second number
            printf("%d\n", num[1] * num[1]);
        } else if (num[0] == 2) {
            scanf("%d %d", &num[1], &num[2]);
            //If number is 2, return the first number raised to the power 
            //of the second 
            int power = pow(num[1], num[2]);
            printf("%d\n", power);
        }
    }
    return 0;
}


    
    
      
