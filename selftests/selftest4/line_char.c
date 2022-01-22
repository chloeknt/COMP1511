//Reads a line from its input then reads an integer n from its input 
//Chloe Toh 

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int main(void) {
    char line[MAX_CHAR];
    fgets(line, sizeof(line), stdin);
    int index = 0;
    scanf("%d", &index);
    printf("The character in position %d is '%c'\n", index, line[index]);
    return 0;
}


