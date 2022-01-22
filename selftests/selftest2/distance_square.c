//Chloe Toh z5362296
//26/04/2021

#include <stdio.h>

int main(void) {
    int n = 0;
    printf("Enter square size: ");
    scanf("%d", &n);
    int i = 0;
    int num = 0;
    num = n - 1;
    while (i < n) {
        if (i < n / 2) {
            int j = 0;
            while (j < n) {
                if (j < n / 2) {
                    printf("%d ", num);
                    num--;
                } else {
                    if (j + 1 == n) {
                        printf("%d ", num);
                        num--;
                    } else {
                        printf("%d ", num);
                        num++;
                    }
                }
                j++;
            }
        } else {
            int j = 0;
            while (j < n) {
                if (j < n / 2) {
                    printf("%d ", num);
                    num--;
                } else {
                    printf("%d ", num);
                    num++;
                }
                j++;
            }
        }
        printf("\n");
        i++;
    }
}
