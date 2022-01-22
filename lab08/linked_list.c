// A demo of a basic linked list

// Marc Chee (cs1511@cse.unsw.edu.au), edited March 2021

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data, struct node *next);
void print_data(struct node* n);

int main (void) {
    // head will always point to the first element of our list
    struct node *head = create_node(5, NULL);
    head = create_node(4, head);
    head = create_node(3, head);
    head = create_node(2, head);
    head = create_node(1, head);
    
    print_data(head);
    
    return 0;
}

// Create a node using the data and next pointer provided
// Return a pointer to this node
struct node *create_node(int data, struct node *next) {
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = data;
    n->next = next;
    return n;
}

// Loop through a list of nodes, printing out their data
void print_data(struct node* n) {
    while (n != NULL) { // have printed from list's head up to just before n
        printf("%d\n", n->data);
        n = n->next;
    }
}
