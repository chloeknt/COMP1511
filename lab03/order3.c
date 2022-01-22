//This program will order the three numbers given by the user into ascending order 
//Chloe Toh
//z5362296

#include <stdio.h> 

int main(void) {
    //Create three variables for the three numbers 
    int first_number;
    int second_number;
    int third_number;
    
    //Ask the user for three numbers
    printf("Enter integer: ");
    scanf("%d", &first_number);
    printf("Enter integer: ");
    scanf("%d", &second_number);
    printf("Enter integer: ");
    scanf("%d", &third_number);
    
    //Order the numbers
    //If the order is already correct
    if (first_number <= second_number && second_number <= third_number) {
        printf("The integers in order are: %d %d %d\n", first_number, 
        second_number, third_number);
        //If the order is not already correct
    } else if (first_number <= third_number && third_number <= 
    second_number) {
        printf("The integers in order are: %d %d %d\n", first_number, 
        third_number, second_number);
    } else if (second_number <= third_number && third_number <=   
    first_number) {
        printf("The integers in order are: %d %d %d\n", second_number, 
        third_number, first_number);
    } else if (second_number <= first_number && first_number <= 
    third_number) {
        printf("The integers in order are: %d %d %d\n", second_number, 
        first_number, third_number);
    } else if (third_number <= second_number && second_number <= 
    first_number) {
        printf("The integers in order are: %d %d %d\n", third_number, 
        second_number, first_number);
    } else {
        printf("The integers in order are: %d %d %d\n", third_number, 
        first_number, second_number);
    }
    
    return 0;
}
      
    
        
        
