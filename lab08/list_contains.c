//Chloe Toh z5362296
//08/04/2021

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int contains(int value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    int value;
    scanf("%d", &value);
    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    int result = contains(value, head);
    printf("%d\n", result);

    return 0;
}


// Return 1 if value occurs in linked list, 0 otherwise
int contains(int value, struct node *head) {
    int result = 0;
    //Loop through a list of nodes
    while (head != NULL) {
        //If the list contains the value, return 1
        if (value == head->data) {  
            result = 1;
            //Set the head to NULL as a match has been found
            head = NULL;
            //If the list doesn't contain the value, return 0
        } else if (value != head->data) {
            result = 0;
            //Move on to the next node
            head = head->next;
        }
    }
    return result;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}
