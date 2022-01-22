//This program will count down from ten to zero
//Chloe Toh
//z5362296

#include <stdio.h>

int main(void) {
    //initialise counter to 10
    int counter = 10; 
    // loop until not >= 0
    while (counter >= 0) { 
        // Have printed all numbers between 10 and counter
        // Print counter
        printf("%d\n", counter);
        // increment counter
        counter = counter - 1; 
    } 
    
    return 0;
}
