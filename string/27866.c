#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1010] = {0,};
    int idx;

    scanf("%s", str);
    scanf("%d", &idx);

    printf("%c", str[idx-1]);
}