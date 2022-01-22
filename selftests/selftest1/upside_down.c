//Program will indicate whether the number inputs are strictly increasing,
//decreasing, or neither 
//Chloe Toh 10/03/2021
//z5362296

#include <stdio.h>

int main(void) {
    //Declare three variables
    double num_one;
    double num_two;
    double num_three; 
    //Ask user for input
    printf("Please enter three numbers: "); 
    //Store input 
    scanf("%lf %lf %lf", &num_one, &num_two, &num_three);
    //Determine the order 
    if (num_one < num_two && num_two < num_three) {
        printf("up\n");
    } else if (num_one > num_two && num_two > num_three) {
        printf("down\n");
    } else {
        printf("neither\n");
    }
    return 0;
}
