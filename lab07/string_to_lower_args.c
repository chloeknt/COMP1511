//Program that will read command line arguments and print them out
//When printed, it will convert all upper case letters to lower case
//Chloe Toh z5362296
//01/04/2021

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_lower(char *s);

int main(int argc, char *argv[]) {
   //While loop for going through each command line argument
   int index = 1;
   while (index < argc) {
        //Call convert lower function
        convert_lower(argv[index]);
        //Print out the new phrase
        printf("%s ", argv[index]);
        index++;
    }
    printf("\n");
}

//Function to go through each character in the string and convert to lowercase
void convert_lower(char *s) {
    //Set the length of the string using strlen
    int len = strlen(s);
    //While loop for going through the string
    int i = 0;
    while (i < len) {
        s[i] = tolower(s[i]);
        i++;
    }
}


