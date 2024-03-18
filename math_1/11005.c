#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int target, jb;
    scanf("%d %d", &target, &jb);
    int namoji;
    char str[32] = {0,};
    int idx = 0;

    while (target != 0)
    {
        namoji = target % jb;
        if (namoji < 10) {
            str[idx++] = namoji + 48;
        }
        else {
            str[idx++] = namoji + 55;
        }

        target /= jb;
    }
    for (int i = strlen(str) - 1 ; i >= 0 ; i--) {
        printf("%c", str[i]);
    }
}
