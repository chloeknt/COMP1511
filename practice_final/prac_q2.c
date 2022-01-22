#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = count_last(head);
    printf("%d\n", result);

    return 0;
}


// return the number of values in a linked list equal to the
// last value in that linked list.
int count_last(struct node *head) {
    //Variables for storing the value of the last node and the number of 
    //the same 
    int last = 0;
    int count = 0;
    //Loop through the list of nodes to find the value stored in the last one
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    //Store this data into the value variable
    last = curr->data;
    //Reset the pointer to the head
    curr = head;
    //Loop through the list and if the data is the same as the value stored
    //increment the count variable
    while (curr != NULL) {
        if (curr->data == last) {
            count++;
        }
        curr = curr->next;
    }
    return count;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
