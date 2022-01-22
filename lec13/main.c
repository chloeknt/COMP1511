/*  Battle Royale - Main File
    A linked list example that tracks players in a game.
    We want to be able to maintain the list
    as well as remove players as they are knocked out.
    We also want to be able to display who is currently
    still in the game.
    
    Marc Chee (cs1511@cse.unsw.edu.au) April 1st 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include "battle_royale.h"

int main(void) {
    Player head = NULL;
    head = insert_alpha(head, "Marc");
    head = insert_alpha(head, "Chicken");
    head = insert_alpha(head, "Goku");
    head = insert_alpha(head, "Vegeta");
    head = insert_alpha(head, "Aang");
    head = insert_alpha(head, "Katara");
    
    while (print_players(head) > 1) {
        head = remove_by_name(head);
        printf("----------\n");
    }
    printf("is the winner!\n");
    free_list(head);
}


