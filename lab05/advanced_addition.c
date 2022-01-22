// Add two numbers together, but in an array.
//Chloe Toh z5362296
//19 March 2021

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 101

int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE] = {0};

    // Get the array size.
    int num_digits, num_rows;
    printf("Enter the number of rows (excluding the last): ");
    scanf("%d", &num_rows);
    assert(num_rows > 0 && num_rows < 100);

    printf("Enter the number of digits on each row: ");
    scanf("%d", &num_digits);
    assert(num_digits > 0 && num_digits < MAX_SIZE);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < num_rows) {
        int j = 0;
        while (j < num_digits) {
            assert(scanf("%d", &array[i][j]) == 1);
            if (array[i][j] < 0 || array[i][j] > 9) {
                printf("You entered a value not between 0 and 9.\n");
                return 1;
            }
            j++;
        }
        i++;
    }

    int carry = sum(num_rows, num_digits, array);

    int j = 0;
    while (j < num_digits) {
        printf("%d ", array[num_rows][j]);
        j++;
    }
    printf("\n");
    i++;

    if (carry > 0) {
        printf("Carried over: %d\n", carry);
    }

    return 0;
}

// Put the sum of the lines in the array into the last line
// accounting for carrying. Return anything you did not carry.
//
// NOTE: num_lines is the number of lines you are adding together. The
// array has an extra line for you to put the result.
int sum(int num_lines, int num_digits, int array[MAX_SIZE][MAX_SIZE]) {
    //Declare and initialise a sum, stay and carry variable
    int sum_var = 0;
    int stay = 0;
    int carry = 0;
    //Declare and initialise an index for the num_digits (right to left)
    int j = num_digits - 1;
    //While loop for the digits (columns)
    while (j >= 0) {
        //Declare and initialise an index for the rows 
        int i = 0;
        //Set the sum variable to 0 before each row loop
        sum_var = 0;
        //Loop to go through each row of the column
        while (i < num_lines) {
            //Add the values together
            sum_var = sum_var + array[i][j];
            i++;
        }
        //Add the carry value from the previous column to the sum value
        sum_var = sum_var + carry;
        //Set the carry to 0 after it is added
        carry = 0;
        //If the sum value for the column is above one digit
        if (sum_var < 9) {
            //Set the value of the last row to the sum value
            array[num_lines][j] = sum_var;
        //Otherwise if it is more than one digit
        } else {
            //Find mod 10 of the sum value and set it as the stay value
            stay = sum_var % 10;
            //Set the value of the last row to the stay value
            array[num_lines][j] = stay;
            //Find the carry value by dividing the sum value by 10
            carry = sum_var / 10;
        }
        j--;
    }
    //If the last carry value exists return it, otherwise return 0
    if (carry > 0) {
        return carry;
    } else {
        return 0;
    }
}
