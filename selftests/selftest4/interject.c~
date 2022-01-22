// COMP1511 Week 7 Test: Interject
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// This program adds interjections to strings.

#include <stdio.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    char new_str[MAX_SIZE];
    //Put the characters in the string up to the index into the new string
    int i = 0;
    while (str[i] != '\0' && i < index) {
        new_str[i] = str[i];
        i++;
    }
    //Put the interject characters into the string
    i = 0;
    int after = 0;
    while (interject[i] != '\0') {
        new_str[index + i] = interject[i];
        i++;
    }
    after = index + i;
    //Put the characters left from the string after the interjected string
    i = 0;
    while (str[index + i] != '\0') {
        new_str[after + i] = str[index + i];
        i++;
    }
    new_str[after + i] = '\0';
    //Transfer the new string into the existing one
    i = 0;
    while (new_str[i] != '\0') {
        str[i] = new_str[i];
        i++;
    }
    str[i] = '\0';
    
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    char str5[MAX_SIZE] = "";
    printf("%s -> ", str5);
    interject(str5, "Test ", 0);
    printf("%s\n", str5);
    
    return 0;
}
