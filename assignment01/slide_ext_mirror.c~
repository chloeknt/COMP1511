// Slide
// slide.c
//
// This program was written by Chloe Toh (z5362296)
// on 15/03/2021
//
// Version 1.0.0 (2021-03-08): Initial Assignment Release

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1
#define SPACES 225

//Function declaration
void print_map(int map[SIZE][SIZE], int laser_y);
void fire_laser(int map[SIZE][SIZE], int laser_y, int index);
void shift_left(int map[SIZE][SIZE], int laser_y);
int shoot_end_condition(int map[SIZE][SIZE], int laser_y);
int shift_end_condition(int map[SIZE][SIZE], int laser_y);
void rotate_map_clock(int map[SIZE][SIZE], int laser_y);
void rotate_map_anticlock(int map[SIZE][SIZE], int laser_y);
int check_block_value(int map[SIZE][SIZE], int laser_y);
void tnt_explode(int map[SIZE][SIZE], int laser_y, int index);
void tnt_checked_explode(int map[SIZE][SIZE], int laser_y, int index, int tnt_radius, int new_position);
void mirror_block(int map[SIZE][SIZE], int laser_y, int index);


int main (void) {
    // This line creates our 2D array called "map" and sets all
    // of the blocks in the map to EMPTY.
    int map[SIZE][SIZE] = {EMPTY};
    // This line creates our laser_y variable. The laser starts in the
    // middle of the map, at position 7.
    int laser_y = SIZE / 2;

    //Ask for the number of blocks 
    printf("How many blocks? ");
    //Scan the number of blocks 
    int blocks;
    scanf("%d", &blocks);
    //Variable for ONE
    int block_value = 0;
    //Create looping variable 
    int keep_looping = 0;
    //Ask for user input 
    printf("Enter blocks:\n");
    
    //Variables for position row and column 
    int pos_r = 0;
    int pos_c = 0;
    //While loop for position of blocks  
    while (keep_looping < blocks) {
        //Scan the user's input 
        scanf("%d %d %d", &pos_r, &pos_c, &block_value);
        //If the input is invalid, disregard it 
        if (0 > pos_r || pos_r > SIZE 
        || 0 > pos_c || pos_c > SIZE) { 
        } else {
            //If it is valid, change the value at that position to the value 
            map[pos_r][pos_c] = block_value;
        }
        keep_looping++;
    }
    //Print the map to see the position of the blocks up to now 
    print_map(map, laser_y);
   
    //Declare and initialise variables for user input 
    int command_one = 0;
    int command_two = 0;
    //Declare and initialise a variable for the shifting end condition
    int last_try = 0;
    //Depending on scanned result, the program either continues or 
    //ends  
    while (keep_looping) {
        //Declare variables for the scans of user input 
        int result_1 = scanf ("%d", &command_one);
        //If the input is ctrl D, end the program
        if (result_1 == EOF) {
            break;
            //If the input is 2 (shooting command)
        } else if (command_one == 2) {
            //Commence check_block_value function
            int index = check_block_value(map, laser_y);
            //If there is no index with non 0 blocks 
            if (index == SIZE) {
                //If the non 0 index is a STONE
            } else if (map[laser_y][index] == STONE) {
                //Commence fire_laser function
                fire_laser(map, laser_y, index);
                //If the non 0 index is a TNT block
            } else if (map[laser_y][index] > 3 && map[laser_y][index] < 10) {
                //Commence tnt_explode function
                tnt_explode(map, laser_y, index);
                //If the non 0 value is anything invalid
            } else if (map[laser_y][index] == 2) {
                //Commence the mirror_block function
                mirror_block(map, laser_y, index);
            } else {
            }
            //Declare and initialise variable for adding up the total 
            //of empty spaces 
            int whole_array = shoot_end_condition(map, laser_y);
            //If the whole array is empty, ie. 225 0s
            if (whole_array == SPACES) {
                //Print the map one more time
                print_map(map, laser_y);
                //Print Game Won and exit the program
                printf("Game Won!\n");
                return 0;
            }
            //If the input is 3 and there has not been a block in the 
            //left most column previously 
        } else if (command_one == 3 && last_try == 0)   {
            //Commence the shift_left function 
            shift_left(map, laser_y);
            //Commence the shift_end_condition function
            int one_try = shift_end_condition(map, laser_y);
            //If the last try has not already been used 
            if (one_try == 1) {
                last_try = one_try;
            }
            //If the input is 3 and there has been a block in the left
            //-most column previously 
        } else if (command_one == 3 && last_try == 1) {
            //Commence the shift_end_condition function
            int one_try = shift_end_condition(map, laser_y);
            //If the last try has been used already
            if (one_try == 1) {
                //Print the map a final time
                print_map(map, laser_y);
                //Print Game Lost and exit the program
                printf("Game Lost!\n");
                return 0;
            }
            //If the commands have two parts to them
        } else {
            //Declare and initilise a variable for the scan of the second input 
            int result_2 = scanf ("%d", &command_two);
            //If the input is ctrl D, exit the program
            if (result_2 != 1) {
                break;
                //If the inputs are 1 1 
            } else if (command_one == 1 && command_two == 1) {
                //Shift laser_y dowmwards once    
                laser_y++;
                //If the inputs are 1 -1
            } else if (command_one == 1 && command_two == -1) { 
                //Shift laser_y upwards once 
                laser_y--; 
                //If the inputs are 4 1 
            } else if (command_one == 4 && command_two == 1 && last_try == 0) {
                //Commence rotate_map_clock function
                rotate_map_clock(map, laser_y);
                last_try++;
                //If the inputs are 4 2
            } else if (command_one == 4 && command_two == 2 && last_try == 0) {
                //Commence rotate_map_anticlock function
                rotate_map_anticlock(map, laser_y);
                last_try++;
            } else if (command_one == 4) {
                last_try++;
            } else if (last_try == 1) {
            }
            //Check if the laser has gone off the map, if so remains 
            //unchanged 
            if (laser_y < 0) { 
                //Too far upwards 
                laser_y = 0; 
            } else if (laser_y >= SIZE) { 
                //Too far downwards  
                laser_y = SIZE - 1; 
            } 
        }
        //Print map to see current position 
        print_map(map, laser_y);
    }
    return 0;
}

//Function for checking the block values in the line of laser_y
int check_block_value(int map[SIZE][SIZE], int laser_y) {
    //Declare and initialise index variable
    int i = SIZE-1;
    //Declare a return variable
    int index = -1;
    //While loop for checking each index value 
    while (i > 0) {
        //If the index value is not EMPTY
        if (map[laser_y][i] != EMPTY) {
            //Change the return variable to the index of this loop
            index = i;
        }
        i--;     
    }
    //If the return value did not change
    if (index == -1) {
        //Set the return value to out of bounds
        index = SIZE;
    } 
    //Return the index value to the main function 
    return index;
}

//Function for firing the laser
void fire_laser(int map[SIZE][SIZE], int laser_y, int index) {
    //Set checking variables for each loop
    int tnt_check = 1;
    int block_check = 0;
    //While loop for checking if any consecutive values within 4 indexes are 
    //TNT blocks
    while (tnt_check < 4 && tnt_check + index < SIZE) {
        //If TNT block is found
        if (map[laser_y][index + tnt_check] > 3 && 
        map[laser_y][index + tnt_check] < 10) {
            //Declare and initialise variable for the value of the 
            //block and the position of the non 1 block
            int tnt_radius; 
            tnt_radius = map[laser_y][index + tnt_check];
            int new_position = index + tnt_check;
            //Commence tnt_checked_explode function
            tnt_checked_explode(map, laser_y, index, tnt_radius, new_position);
        } else {
            //If TNT block is not found, add to the tnt_check index
            tnt_check++; 
        }
    }
    //While loop for checking if any values consecutively within 4 indexes 
    //are STONES
    while (block_check < 4 
    && index + block_check < SIZE) {
        //Up to four STONE blocks consecutively after are destroyed
        map[laser_y][index + block_check] = EMPTY;
        block_check++;
    }

} 

//Function for exploding any TNT blocks within four consecutive indexes 
void tnt_checked_explode(int map[SIZE][SIZE], int laser_y, int index, 
int tnt_radius, int new_position) {
    //Declare and initialise variable for index variables 
    int i = 0;
    //While loop to check every value in the array
    while (i < SIZE) {
        int j = 0; 
        while (j < SIZE) {
            //Blocks within the euclidean distance of the block 
            //value are destroyed (changed to 0)
            if (tnt_radius > 
            sqrt(pow((j - new_position), 2) + pow((i - laser_y), 2))) {
                map[i][j] = EMPTY;
            }
            j++;
        }
        i++;
    } 
}

//Function for exploding TNT blocks     
void tnt_explode(int map[SIZE][SIZE], int laser_y, int index) {
    //Destroying TNT blocks (4-9)s
    //Declare and initialise variable for the value of the block 
    int tnt_radius; 
    tnt_radius = map[laser_y][index];
    //Declare and initialise variable for index variables 
    int i = 0;
    //While loop to check every value in the array
    while (i < SIZE) {
        int j = 0; 
        while (j < SIZE) {
            //Blocks within the euclidean distance of the block 
            //value are destroyed (changed to 0)
            if (tnt_radius > sqrt(pow((j - index), 2) + 
            pow((i - laser_y), 2))) {
                map[i][j] = EMPTY;
            }
            j++;
        }
        i++;
    }
}    

//Function that will shift everything to the left
void shift_left(int map[SIZE][SIZE], int laser_y) {
    //Declare and initialise index variable
    int i = 0;
    //Declare variable for storing array value
    int saved;
    //Declare and initialise pointer for saved variable
    int *p = &saved;
    //While loop for shifting all the values in each index to the left
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            *p = map[i][j];
            p = &map[i][j];
            j++;
        }
        i++;
    }
    *p = saved;
}

//Function that rotates map 90 degress clockwise
void rotate_map_clock(int map[SIZE][SIZE], int laser_y) {
    //First, transpose the elements 
    //Initialise a temporary variable for storage
    int temp;
    //Declare and initialise index variables
    int i = 0;
    //While loop for moving each value of the index from [row][column] to
    //[column][row]
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if (i < j) {
                temp = map[i][j]; 
                map[i][j] = map[j][i];
                map[j][i] = temp;
            }
            j++;
        }
        i++;
    }
    //Then, reverse the rows
    //Declare and initialise index variables
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            //For vertically-half the array, swap opposite values per index  
            if (col < SIZE/2) {
                temp = map[row][col];
                map[row][col] = map[row][SIZE - col - 1]; 
                map[row][SIZE - col - 1] = temp;
            }
            col++;
        }
        row++;
    }
    
}

//Function that rotates map 90 degress anticlockwise
void rotate_map_anticlock(int map[SIZE][SIZE], int laser_y) {
    //First we reverse the rows 
    //Declare and initialise index variables
    int temp;
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            //For vertically-half the array, swap opposite values per index  
            if (col < SIZE/2) {
                temp = map[row][col];
                map[row][col] = map[row][SIZE - col - 1]; 
                map[row][SIZE - col - 1] = temp;
            }
            col++;
        }
        row++;
    }
    //Then, transpose the elements 
    //Declare and initialise index variables
    int i = 0;
    //While loop for moving each value of the index from [row][column] to
    //[column][row]
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if (i < j) {
                temp = map[i][j]; 
                map[i][j] = map[j][i];
                map[j][i] = temp;
            }
            j++;
        }
        i++;
    }  
}

//Check if the entire map is empty 
int shoot_end_condition(int map[SIZE][SIZE], int laser_y) {
    //Declare and initialise index variable 
    int i = 0;
    //Declare and initialise a variable for the number of filled array indexes
    int whole_array = 0;
    //While loop for checking every value in the array 
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if (map[i][j] == EMPTY) {
                //If the value is 0, add to the variable whole_array
                whole_array++; 
            }
            j++;
        }
        i++;
    }
    //Return whole_array value to the main function
    return whole_array;
}

int shift_end_condition(int map[SIZE][SIZE], int laser_y) {
    //Declare and initialise index variable
    int i = 0;
    //Declare and initialise a variable for the last possible shift
    int one_try = 0;
    //While loop to check if the left-most column has any blocks
    while (i < SIZE) {
        //If there are blocks, change the one_try variable
        if (map[i][0] != EMPTY) {
            one_try = 1;
        }
        i++; 
    }
    //Return one_try variable back to main function
    return one_try;
}

// Print out the contents of the map array. 
// Also print out a > symbol to denote the current laser position.
void print_map(int map[SIZE][SIZE], int laser_y) {
    //Declare and initialise index variables
    int i = 0;
    //While loop for the position of the laser
    while (i < SIZE) {
        if (i == laser_y) {
            printf("> ");
        } else {
            printf("  ");
        }
        int j = 0;
        //While loop for the value of the array indexes
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        //Print a new ine for the end of each row 
        printf("\n");
        i++;
    }
}


void mirror_block(int map[SIZE][SIZE], int laser_y, int index) {
//Set checking variables for each loop
    int mirror_check = 0;
    //While loop for checking if any values consecutively within 4 indexes 
    //are STONES
    while (mirror_check < 3 
    && index + mirror_check < SIZE) {
        //Up to two blocks perpendicular to the mirror block
        //consecutively after are destroyed
        map[laser_y + mirror_check][index] = EMPTY;
        map[laser_y - mirror_check][index] = EMPTY;
        mirror_check++;
    }
}
