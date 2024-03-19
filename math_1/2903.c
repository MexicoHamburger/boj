/*
0단계 : 2 * 2
1단계 : (2 + 1)^2
2단계 : (3 + 2)^2
3단계 : (5+4)^2 ..
*/
#include <stdio.h>

int main()
{
    int n, edge = 2;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        edge = 2 * edge - 1;
    }
    printf("%d", edge * edge);
}