//A program that will scan indices until EOF and then print out a 
//one dimensional array which has 36 '0's, expect at the given indices it 
//has a '1'.
//Chloe Toh 12/03/2021
//z5362296

#include <stdio.h>
//Define the maximum size of the canvas
#define CANVAS_SIZE 36

int main (void) {
    //Declare the array
    int canvas[CANVAS_SIZE] = {0};
    //Declare a variable for the positional input
    int position_value;
    //Declare an index variable
    int i = 0;
    //Make a loop for inputs and change them to 1 when they exist
    while (scanf("%d", &position_value) != EOF) {
        canvas[position_value] = 1;
    }
    //Loop that prints out the array
    while (i < CANVAS_SIZE) {
        printf("%d", canvas[i]);
        i++;
    }
    printf("\n");
    return 0;
}

