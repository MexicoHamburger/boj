#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int cnt = 0;
    for (int i = 1 ; i <= a ; i++) {
        if (a % i == 0) {
            cnt++;
            if (cnt == b) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("0\n");
    return 0;
}