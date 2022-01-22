// a program for determining all the possible rolls of the pair of dice 
// it will be able to tell us the odds of rolling a particular number (as the total of both dice).
// Chloe Toh 26/02/2021
//z5362296

#include <stdio.h>

int main(void) {
    int die_one_size = -1;
    int die_two_size = -1;
    int target_value = -1;
    
    //let the user decide the size of the two dice
    printf("Please enter the size of the first die: ");
    scanf("%d", &die_one_size);
    printf("Please enter the size of the second die: ");
    scanf("%d", &die_two_size);
    //let the user decide the size of the total roll they desire 
    printf("Please enter the number you wish to roll: ");
    scanf("%d", &target_value);
    
    //set up two counters to keep track of total rolls and the number of 
    //rolls that matched the target
    int total_rolls = 0;
    int matching_rolls = 0; 
    
    //loop through both dice and see all the possibilities of their
    //combined values 
    
    int die_one_value = 1;
    while (die_one_value <= die_one_size) { // i am in the 
                                            // die_one_value'th run
        int die_two_value = 1;
        while (die_two_value <= die_two_size) { 
            int total = die_one_value + die_two_value;
             if (total == target_value) {
                printf("Die One: %d, Die Two: %d, Total: %d\n", 
                die_one_value, die_two_value, total);
                matching_rolls++;
            }
            total_rolls++; 
            die_two_value++;
        }
        die_one_value++;
    }
    
    //summary of results
    printf("There are %d permutations and %d matched the target of %d\n", 
    total_rolls, matching_rolls, target_value);
    printf("The %% chance of rolling %d with dice sized %d and %d, is %lf\n", target_value, die_one_size, die_two_size, (matching_rolls * 100.0)/total_rolls);
}
