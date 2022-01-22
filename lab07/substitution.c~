//Program which reads characters from its input and write the characters to 
//its output encrypted with a substitution cipher 
//Chloe Toh z5362296
//01/04/2021

#include <stdio.h>
#include <string.h>

#define ALPHA_SIZE 26

int encrypt(int character, char string[ALPHA_SIZE]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    if (strlen(argv[1]) != ALPHA_SIZE) {
        printf("To encrypt, mapping must contain %d letter\n", ALPHA_SIZE);
        return 1;
    }
    //Read user's input
    int character = getchar();
    //While the character is valid 
    while (character != EOF) {
        //Call the encrypt function
        int new_character = encrypt(character, argv[1]);
        //Print out the new modified character 
        putchar(new_character);
        //Set the character to the next input 
        character = getchar();
    }
    return 0;
}

//Function for encrypting the characters by shifting a certain number of spaces
int encrypt(int character, char string[ALPHA_SIZE]) {
    //If the character is lowercase
    if (character >= 'a' && character <= 'z') {
        return string[character - 'a'];
        //If the character is uppercase
    } else if (character >= 'A' && character <= 'Z') {
        return string[character - 'A'] - 'a' + 'A';
        //If the character isn't a letter
    } else {
        return character;
    }
}
