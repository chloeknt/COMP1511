// A heavily modified version of slide.c for Assignment 1

// This is starter code for the Tourist Program

// Marc Chee (cs1511@cse.unsw.edu.au)
// June 2019 - March 2021
//

#include <stdio.h>

// The dimensions of the map
#define N_ROWS 10
#define N_COLS 10

#define EXPLORED 1
#define UNEXPLORED 0 

// Helper Function: Print out the map as a 2D grid
void print_map(int map[N_ROWS][N_COLS], int pos_r, int pos_c);


int main(void) {
    int map[N_ROWS][N_COLS] = {}; 
	int pos_r, pos_c; 
	//giving the tourist a position in the middle of the map  
	pos_r = N_ROWS/2; 
	pos_c = N_COLS/2;  
	print_map(map, pos_r, pos_c); 
    //looping for multiple turns  

	int keep_looping = 1; 

    while (keep_looping) { 
        //track where we've been 
        map[pos_r][pos_c] = EXPLORED;
        printf("Type in 2,4,6 or 8 to move in that numpad direction: ");
	    int input = 0; 

	    int input_result = scanf ("%d", &input ); 
	    if (input_result != 1) { 
	        keep_looping = 0; 
	    } else {  
		//input was a number, check which direction to go  
		if (input == 8) { 
			//up   
            pos_r--;
		} else if (input == 6) { 
			//right  
            pos_c++;
		} else if (input == 4) { 
			// left 
            pos_c--;
		} else if (input == 2) { 
			//down 
            pos_r++;
		} else { 
			//invalid or any other number 
		keep_looping = 0;  
		}
	}
	//check if we've gone off the map  
	//clamp to legal map positions 
	if (pos_r < 0) { 
		//top 
		pos_r = 0; 
	} else if (pos_r >= N_ROWS) { 
		//bottom 
		pos_r = N_ROWS - 1; 
	} else if (pos_c < 0) { 
		//left 
		pos_c = 0;  
	} else if (pos_c >= N_COLS) { 
		//right  
		pos_c = N_COLS - 1;
    }
	print_map(map, pos_r, pos_c); 
	// check to see if current location was already explored
        if (map[pos_r][pos_c] == EXPLORED) {
        printf("I have already been here, HOW BORING!\n");
        keep_looping = 0;
        }
    }
    return 0;
}


// Prints the map, by printing the integer value stored in
// each element of the 2-dimensional map array.
// Prints a T instead at the position posR, posC
void print_map(int map[N_ROWS][N_COLS], int pos_r, int pos_c) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            if(pos_r == row && pos_c == col) {
                printf("T ");
            } else {
                printf("%d ", map[row][col]);
            }            
            col++;
        }
        row++;
        printf("\n");
    }
}

