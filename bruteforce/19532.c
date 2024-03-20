#include <stdio.h>

int main()
{
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    for (int x = -1000 ; x <= 1000 ; x++) {
        for (int y = -1000 ; y <= 1000 ; y++) {
            if (a*x + b*y == c && d*x + e*y == f) {
                printf("%d %d", x, y);
            }
        }
    }
}