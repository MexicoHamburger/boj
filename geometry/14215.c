#include <stdio.h>

int main()
{
    int a, b, c;
    int largest = 0;
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        printf("%d", a + b + c);
    }
    else {
        if (a + b > c && b + c > a && a + c > b) {
            printf("%d", a+b+c);
        }
        else {
            if (a + b <= c) {
                printf("%d", 2 * (a+b) - 1);
            }
            else if (a + c <= b) {
                printf("%d", 2 * (a+c) - 1);
            }
            else if (b + c <= a) {
                printf("%d", 2 * (b+c) - 1);
            }
        }
    }
}