//Chloe Toh z5362296
//26/04/2021

#include <stdio.h>

int main (void) {
    int number = 0;
    int value = 0;
    printf("How many numbers: ");
    scanf("%d", &number);
    int i = 0;
    int sum = 0;
    while (i < number) {
        scanf("%d", &value);
        sum += value;
        i++;
    }
    printf("The sum is: %d\n", sum);
}
