/*  Battle Royale - Implementation File
    A linked list example that tracks players in a game.
    We want to be able to maintain the list
    as well as remove players as they are knocked out.
    We also want to be able to display who is currently
    still in the game.
    
    Marc Chee (cs1511@cse.unsw.edu.au) April 1st 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "battle_royale.h"

// Structs
struct player {
    struct player *next;
    char name[MAX_NAME_LENGTH];
};

// Allocate memory for a player node
// Populate that node with new_name and new_next
// Return a pointer to the allocated memory
Player create_player(char new_name[MAX_NAME_LENGTH], Player new_next) {
    Player new_player = malloc(sizeof (struct player));
    new_player->next = new_next;
    strcpy(new_player->name, new_name);
    return new_player;
}

// Takes the head of the list
// Prints out everyone who is in the list
int print_players(Player head) {
    Player current = head;
    int num_players = 0;
    while (current != NULL) { // I'm looking at a valid player
        printf("%s\n", current->name);
        num_players++;
        current = current->next;
    }
    return num_players;
}

// Inserts a node into a linked list after the node insert_pos
// Assumes that this is a working linked list
Player insert_after(Player insert_pos, char new_name[MAX_NAME_LENGTH]) {
    if (insert_pos == NULL) {
        // Inserting into an empty list
        Player new_player = create_player(new_name, NULL);
        insert_pos = new_player;
    } else {
        // Inserting into a list that already exists.
        // Create the new player using the next of insert_pos
        Player new_player = create_player(new_name, insert_pos->next);
            
        // Change the insert_pos' next to now aim at the new player
        insert_pos->next = new_player;
    }

    return insert_pos;
}

// Inserts into a list (head) alphabetically.
// Assumes the list is already in alphabetical order
// Returns the head of the list (it may have changed)
Player insert_alpha(Player head, char new_name[MAX_NAME_LENGTH]) {
    // loop through and find the insertion point
    Player curr = head;
    Player prev = NULL;    
    while (curr != NULL && strcmp(curr->name, new_name) < 0) {
        // go past any names that are earlier than us alphabetically
        prev = curr;
        curr = curr->next;
    } // curr is now the first player in the list with a name "higher or equal"
      // than new_name
      // prev is now the last player in the list with a name "lower"
      // than new_name
    
    Player insert_result = insert_after(prev, new_name);

    // Inserting at the head of a list (also works for an empty list)
    if (prev == NULL) {
        insert_result->next = head;
        head = insert_result;
    }
    
    return head;
}

// Loop through list looking for a match between a player's name and rem_name
// Remove and free that node (if it exists)
// Return the head of the list (special case if we removed the old head)
Player remove_player(Player head, char rem_name[MAX_NAME_LENGTH]) {
    // Loop through and stop with curr->name == rem_name
    Player curr = head;
    Player prev = NULL;
    while (curr != NULL && strcmp(rem_name, curr->name) != 0) {
        prev = curr;
        curr = curr->next;
    }   
    
    if (curr != NULL) {
        // curr is now pointing at a player who's name matches rem_name        
        if (prev == NULL) { // (head == curr) also works
            // removing the head of the list
            head = curr->next;
        } else {
            // removing an element somewhere other than the head
            prev->next = curr->next;
        }        
        free(curr); 
    } 
    // or curr is NULL if it has reached the end of the list
    
    return head;
}

// Ask the user for a player's name to remove.
// Remove that node and return the head of the list (may have changed)
Player remove_by_name(Player head) {
    printf("Who's just been knocked out?\n");
    char input[MAX_NAME_LENGTH];
    fgets(input, MAX_NAME_LENGTH, stdin);
    // fgets will store the \n that we type in in the input string
    // if we find a \n at the end of input, remove it from the string
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    head = remove_player(head, input);
    return head;
}

// Free all elements of the list starting at head
void free_list(Player head) {
    Player curr = head;
    while (curr != NULL) {
        Player free_node = curr;
        curr = curr->next;
        free(free_node);
    }
}

 
