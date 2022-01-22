//Reads characters and prints their decimal values

#include <stdio.h>

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        printf("%d\n", ch);
        ch = getchar();
    }
}
