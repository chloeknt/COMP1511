//Program will copy all of the values in source1 which are also found in 
//source2 into destination
//It will then return the number of elements copied into destination
//Chloe Toh z5362296
//18 March 2021


#include <stdio.h>

int common_elements(int length, int source1[length], int source2[length], int destination[length]); 


int main(void) {
    int source1[5] = {1,2,3,4,5};
    int source2[5] = {1,2,3,2,1};
    int destination[5] = {0};
    int length;

    int total = common_elements(5, source1, source2, destination);
    int j = 0;
    while (j < 5) {
        printf("%d ", destination[j]);
        j++;
    }
    printf("\n");
    printf("Carried over: %d\n", total);
   return 0;
}

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    //Declare and initialise index variables and a looping variable
    int total = 0;
    int i = 0;
    int j = 0;
    int keep_looping = 1;
    //Loop in order to find reoccuring numbers
    while (i < length) { 
        //This variable helps to determine if the number already exists
        keep_looping = 1;
        while (j < length && keep_looping ==1) {
            //If statement for common elements 
            if (source1[i] == source2[j]) {
                //Put the common element in the third array 
                destination[total] = source1[i];
                total++;
                keep_looping = 0;
            } else {
            }
            j++;
        }
        j = 0; 
        i++;
    }
    //Return the number of elements in the third array 
    return total;
}


