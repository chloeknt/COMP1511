//A program which reads characters form its input and writes the characters to
//its output encrypted with a caesar cipher, which shifts each letter a certain 
//number of positions in the alphabet 
//Chloe Toh z5362296
//01/04/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int encrypt(int character, int shift);

int main(int argc, char *argv[]) {
    //Declare and initialise index and shift variable
    int index = 1;
    int shift = 0;
    //Change the command line argument to an integer using a while loop
    while (index < argc) {
        shift = atoi(argv[index]);
        index++;
    }
    //Read user's input
    int character = getchar();
    //While the character is valid 
    while (character != EOF) {
        //Call the encrypt function
        int new_character = encrypt(character, shift);
        //Print out the new modified character 
        putchar(new_character);
        //Set the character to the next input 
        character = getchar();
    }
}

//Function for encrypting the characters by shifting a certain number of spaces
int encrypt(int character, int shift) {
    //If the character is lowercase
    if (character >= 'a' && character <= 'z') {
        //Ensure the characters stay within the lowercase alphabet
        while (character + shift < 'a') {
            shift += 'z' - 'a' + 1;
        }
        while (character + shift > 'z') {
            shift -= 'z' - 'a' + 1;
        }
        //Shift the character by that number of spaces
        int new_character = character + shift;
        return new_character;
        //If the character is uppercase
    } else if (character >= 'A' && character <= 'Z') {
        //Ensure the characters stay within the uppercase alphabet
        while (character + shift < 'A') {
            shift += 'Z' - 'A' + 1;
        }
        while (character + shift > 'Z') {
            shift -= 'Z' - 'A' + 1;
        }
        //Shift the character by that number of spaces
        int new_character = character + shift;
        return new_character;
        //If the character isn't a letter
    } else {
        return character;
    }
}
