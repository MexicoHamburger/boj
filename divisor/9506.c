#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    while (a != -1)
    {
        int yaksu[100] = {0,};
        int sum = 0;
        int idx = 0;
        for (int i = 1 ; i < a ; i++) {
            if (a % i == 0) {
                sum += i;
                yaksu[idx++] = i;
            }
        }
        if (sum == a) {
            printf("%d = %d ", a, yaksu[0]);
            for (int i = 1 ; i < idx ; i++) {
                printf("+ %d ", yaksu[i]);
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", a);
        }
        scanf("%d", &a);
    }
    return 0;
}