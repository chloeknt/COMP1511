// COMP1511 Array Sum Product
// Calculate the sum and the product of the elements in an array
// and write the results into variables passed into the function
// by reference.

// This program was written by Chloe Toh (z5362296)
// on 18 March 2021

#include <stdio.h>

void array_sum_prod(int length, int nums[length], int *sum, int *product);


int main(void) {
    int nums[] = {3, 4, 1, 5, 6, 1};
    int prod;
    int sum;

    //Pass in the address of the sum and product variables
    array_sum_prod(6, nums, &sum, &prod);

    printf("Sum: %d, Product: %d\n", sum, prod);
   
    int nums2[] = {1, 2, 3, 4};

    //Pass in the address of the sum and product variables
    array_sum_prod(4, nums2, &sum, &prod);

    printf("Sum: %d, Product: %d\n", sum, prod);
   
    return 0;
}


// Calculates the sum and product of the array nums.
// Actually modifies the  variables that *sum and *product are pointing to
void array_sum_prod(int length, int nums[length], int *sum, int *product) {
    //Declare and initialise index variables and placeholder variables 
    int index = 0;
    int product_var = 1;
    int sum_var = 0;
    //While loop for the elements that exist in the array
    while (index < length) {
        //Add the elements together
        sum_var = sum_var + nums[index];
        //Multiply the elements together
        product_var = product_var * nums[index];
        index++;
    }
    //Declare and initialise pointers 
    int *prod_ptr = &product_var;
    int *sum_ptr = &sum_var;
    *sum = *sum_ptr;
    *product = *prod_ptr;
}
