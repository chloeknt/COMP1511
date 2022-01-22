// exam_q1.c
//
// This program was written by CHLOE TOH (z5362296)
// on 01/05/2021
//
// Returns the number of decreasing pairs in the array.
#include <stdio.h>

// Return the number of decreasing pairs in the array.
int count_decreasing(int size, int array[size][2]) {
    //Variable for counting the decreasing pairs
    int number = 0;
    //Incremental counter
    int i = 0;
    //Loop through the array 
    while (i < size) {
        //If the first number is greater than the second, increment
        //the number counter
        if (array[i][0] > array[i][1]) {
            number++;
        }
        i++;
    }
    return number;
}

// This is a simple main function which could be used
// to test your count_decreasing function.
// It will not be marked.
// Only your count_decreasing function will be marked.

#define TEST_ARRAY_SIZE 5

int main(void) {
    int test_array[TEST_ARRAY_SIZE][2] = {{16, 7}, {8, 12}, {13, -9}, {-3, 12}, {1, 1}};

    int result = count_decreasing(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
