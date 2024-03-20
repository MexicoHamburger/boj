#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 6 // 문자열의 최대 길이 (널 종료 문자를 포함하여 5글자까지 가능)

int compare(const void *a, const void *b)
{
    return strcmp(*(const char(*)[MAX_LEN])a, *(const char(*)[MAX_LEN])b);
}
int main()
{
    char ppl[1000010][6] = {0,};

    int n;
    int idx = 0;
    char name[6] = {0,};
    char log[6] = {0,};
    scanf("%d", &n);

    for (int i = 0 ; i < n ; i++) {
        scanf(" %s %s", name, log);
        if (!strcmp(log, "enter")) {
            strcpy(ppl[idx++], name);
        }
        else if (!strcmp(log, "leave")) {
            for (int i = 0 ; i < idx ; i++) {
                if (!strcmp(ppl[i], name)) {
                    for (int j = i ; j < idx ; j++) {
                        strcpy(ppl[j+1], ppl[j]);
                    }
                }
            }
            idx--;
        }
    }
    qsort(ppl, idx, sizeof(ppl[0]), compare);
    for (int i = 0 ; i < idx ; i++) {
        printf("%s\n", ppl[i]);
    }
}