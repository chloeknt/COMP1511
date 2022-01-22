// A loop within a loop. These should draw a grid of
// stars
//Chloe Toh
//z5362296

#include <stdio.h>

int main(void) {  
    int y = 0;
    // loop through and print multiple rows
    while (y < 10) { // we have printed y rows
        // print a single row
        int x = 0;
        while (x < 10) { // we have printed x stars in this row
            printf("*");
            x = x + 1;
        }
        // the row is finished, start the next line
        printf("\n");
        y = y + 1;
    }

    return 0;
}
