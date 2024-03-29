/*
무식하게 10만회의 검색을 선형으로 돌리면 최대 100억번의 연산을 해야 한다.
시간초과 무조건 남.

첫문자를 기준으로 해싱해주는게 나을듯.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_int (char* str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
typedef struct _pokemon {
    char name[21];
    int num;
    struct _pokemon* next;
} pokemon;

int hash_function (char* name) {
    return name[0] - 'A';
}

int main()
{
    int n, m;
    char* pkname[100010] = {0};
    scanf("%d %d", &n, &m);

    pokemon* hash_table[26];
    memset(hash_table, 0, sizeof(hash_table));

    for (int i = 1 ; i <= n ; i++)
    {
        pokemon* new_pk = (pokemon*)malloc(sizeof(pokemon));
        scanf("%s", new_pk->name);
        new_pk->num = i;
        pkname[i] = new_pk->name;

        int idx = hash_function(new_pk->name);
        new_pk->next = hash_table[idx];
        hash_table[idx] = new_pk;
    }
    for (int i = 0 ; i < m ; i++)
    {
        char input[30];
        scanf("%s", input);
        
        //printf("on work : %d, input %s\n", i, input);
        if (is_int(input)) {
            printf("%s\n", pkname[atoi(input)]);
        }
        else {
            int idx = hash_function(input);
            //printf("%d\n", idx);
            pokemon* pk = hash_table[idx];

            while (strcmp(pk->name, input)) {
                pk = pk->next;
            }
            printf("%d\n", pk->num);
        }
    }
}