#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[100] = {0,};
    int jb;

    scanf("%s %d", str, &jb);
    int pw = 0;
    int sum = 0;
    for (int i = strlen(str)-1 ; i >= 0 ; i--) {
        if (48 <= str[i] && str[i] <= 57) {
            sum += (pow(jb, pw) * (str[i] - 48));
            pw++;
        }
        else if (65 <= str[i] && str[i] <= 90) {
            sum += (pow(jb, pw) * (str[i] - 55));
            pw++;
        }
    }
    printf("%d", sum);
}