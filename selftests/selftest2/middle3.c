//Chloe Toh z5362296
//26/04/2021

#include <stdio.h>

int main (void) {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int middle = 0;
    printf("Enter integer: ");
    scanf("%d", &num1);
    printf("Enter integer: ");
    scanf("%d", &num2);
    printf("Enter integer: ");
    scanf("%d", &num3);
    if (num1 > num2 && num1 < num3) {
        middle = num1;
    } else if (num1 < num2 && num1 > num3) {
        middle = num1;
    } else if (num1 == num2) {
        middle = num1;
    } else if (num2 > num1 && num2 < num3) {
        middle = num2;
    } else if (num2 < num1 && num2 > num3) {
        middle = num2;
    } else if (num2 == num3) {
        middle = num2;
    } else {
        middle = num3;
    } 
    printf("Middle: %d\n ", middle);
}
