/*  Battle Royale - Header File
    A linked list example that tracks players in a game.
    We want to be able to maintain the list
    as well as remove players as they are knocked out.
    We also want to be able to display who is currently
    still in the game.
    
    Marc Chee (cs1511@cse.unsw.edu.au) April 1st 2021
*/

#define MAX_NAME_LENGTH 100

// "Player" now means the same thing as "struct player *"
typedef struct player *Player;

// Create a player by allocating memory,
// populating their data then returning a pointer to them
Player create_player(char new_name[MAX_NAME_LENGTH], Player new_next);

// Loop through and display the players
// One per line in the terminal
// Returns the number of players that it printed out
int print_players(Player head);

// Insert a player node into a list after a given Player
// Returns the insert_pos, or a pointer to the new list
// if it had been given an empty list
Player insert_after(Player insert_pos, char new_name[MAX_NAME_LENGTH]);

// Insert into a list alphabetically
// Returns the head of the list (even if it has changed)
Player insert_alpha(Player head, char new_name[MAX_NAME_LENGTH]);

// Find the player that matches rem_name in the list starting at head
// Remove and free that player, return the head (it may have changed)
Player remove_player(Player head, char rem_name[MAX_NAME_LENGTH]);

// Ask for input from the user to remove a player.
// Return the head of the list (it may have changed)
Player remove_by_name(Player head);

// Free all the players in the given list
void free_list(Player head);

