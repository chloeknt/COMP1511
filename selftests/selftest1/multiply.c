//This program will read two integers given by the user and print the 
//absolute value of their multiple 
//Chloe Toh 10/03/2021
//z5362296

#include <stdio.h> 

int main(void){
    int integer_one;
    int integer_two;
    scanf("%d %d", &integer_one, &integer_two);
    int product = integer_one * integer_two;
    if (product > 0) {
        printf("%d\n", product);
    } else if (product == 0) {
        printf("zero\n");
    } else {
        printf("%d\n", product * -1);
    }
    return 0;
} 
