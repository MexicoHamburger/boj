#include <stdio.h>
#include <string.h>

int main()
{
    char str[101];
    char reversed[101];

    scanf("%s", str);
    for (int i = 0 ; i < strlen(str) ; i++) {
        reversed[i] = str[strlen(str)-1 -i];
    }
    for (int i = 0 ; i < strlen(str) ; i++) {
        if (str[i] != reversed[i]) {
            printf("0");
            return 0;
        }
    }
    printf("1");
}