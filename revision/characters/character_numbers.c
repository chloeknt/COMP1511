//Prints out the integers 32 to 126 
//Chloe Toh

#include <stdio.h>

int main(void) {
    char ch = 32;
    while (ch < 127) {
        printf("%d 0x%x %c\n", ch, ch, ch);
        ch++;
    }
    return 0;
}
