// exam_q5.c
//
// This program was written by CHLOE TOH (z5362296)
// on 01/05/2021
//
// Prints out the least common command line argument 
// (excluding the program name). If there are multiple equally 
// least-common arguments, print out the one that appears first in the list.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ARGS 1000

int main(int argc, char *argv[]) {
    int index1 = 1;
    int same = MAX_ARGS - 1;
    int chosen = 0;
    while (index1 < argc) {
        int index2 = 1;
        int count = 0;
        while (index2 < argc) {
            if (strcmp(argv[index1], argv[index2]) == 0) { 
                count++;
            } 
            index2++;
        }
        if (count < same) {
            same = count;
            chosen = index1;
        } 
        index1++;
    }
    printf("%s", argv[chosen]);
    return 0;
}
