// exam_q2.c
//
// This program was written by CHLOE TOH (z5362296)
// on 01/05/2021
//
// Takes in the head of two lists and prints
// something based on which has the larger sum

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *strings_to_list(int len, char *strings[]);

// exam_q2() takes in the head of two lists and prints
// something based on which has the larger sum
int exam_q2(struct node *first, struct node *second){
    //Pointer to the first node of the first list
    struct node *curr1 = first;
    //Variable to store the sum 
    int sum1 = 0;
    //Loop through the first list and sum all the elements
    while (curr1 != NULL) {
        sum1 += curr1->data;
        curr1 = curr1->next;
    }
    //Pointer to the first node of the second list
    struct node * curr2 = second;
    //Variable to store the sum 
    int sum2 = 0;
    //Loop through the second list and sum all the elements
    while (curr2 != NULL) {
        sum2 += curr2->data;
        curr2 = curr2->next;
    }
    //If the sum of the first list is greater than the sum of the second
    if (sum1 > sum2) {  
        return 1;
        //If the sum of the first list is less than the sum of the second
    } else if (sum1 < sum2) {
        return -1;
        //If the sums are equal
    } else {
        return 0;
    }
}



// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *first = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *second = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = exam_q2(first, second);
    printf("%d\n", result);

    return 0;
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
