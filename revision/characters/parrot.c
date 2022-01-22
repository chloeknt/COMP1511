//Use getchar() and putchar() to echo the user's input

#include <stdio.h>

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        putchar(ch);
        ch = getchar();
    }

}
