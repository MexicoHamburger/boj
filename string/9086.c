#include <stdio.h>
#include <string.h>

int main()
{
    int tc; scanf("%d", &tc);

    for (int i = 1 ; i <= tc ; i++) {
        char str[1001] = {0,};
        scanf("%s", str);
        printf("%c%c\n", str[0], str[strlen(str)-1]);
    }
}