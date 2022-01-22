//A program that will read characters from its input and write the same 
//characters expect without the lower case vowels present. 
//Chloe Toh z5362296
//31/03/2021

#include <stdio.h>

//Function for detemining if a character is a lower case vowel
int is_vowel(int character);

int main(void) {
    //Declare a character and read from terminal
    int character = getchar();
    //While the character is valid 
    while (character != EOF) {
        //Run the vowel checking function
        int result = is_vowel(character);
        //If the return value was 1, meaning it is a vowel
        if (result == 1) {
            //If the return value was 1, meaning it is not a vowel
        } else if (result == 0) {
            //Print out the characters 
            putchar(character);
        }
        //Set the character to the next input 
        character = getchar();
    }
    return 0;
}

int is_vowel(int character) {
    //If the character is a lower case vowel return 1
    if (character == 'a' || character == 'e' 
    || character == 'i'|| character == 'o' || 
    character == 'u'  ) {
        return 1;
        //If not return 0
    } else {
        return 0;
    }
}
