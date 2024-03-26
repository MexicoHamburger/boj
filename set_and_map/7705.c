#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    char* name1 = ((char(*)[6])a)[0];
    char* name2 = ((char(*)[6])b)[0];
    return strcmp(name2, name1);
}

int main() {
    int n;
    scanf("%d", &n);
    char namestack[100010][6] = {0};
    for (int i = 0; i < n; i++) {
        char log[10] = {0}; 
        scanf("%s %s", namestack[i], log);
    }
    qsort(namestack, n, sizeof(namestack[0]), compare);

    for (int i = 0; i < n; i++) { 
        if (!strcmp(namestack[i], namestack[i+1])) {
            i++;
        }
        else {
            printf("%s\n", namestack[i]);
        }
    }

    return 0;
}


/*
COMPARE 함수 사용법!
인자 a, b에서 return값이 1이면 a, b가 SWAP되어야 한다는 뜻이다.

name1, name2를 인자로 받았을 때,
name1 < name2 --> return 1이라면
순행으로 저장하라는 뜻.

또한, compare 함수 인자는 (void*)로 변환되어 들어오는데,
그걸 쓰고자 하는 인자로 형변환을 해줘야 한다.

우리가 쓰는 namestack 배열은 namestack[*][6] 꼴이므로, 이차원배열을 캐스팅할 때 뒤쪽 크기가 중요하니까

char* [6]으로 캐스팅해서 넘어온 a, b에 대해
a[0] = namestack[0], b[0] = namestack[1]처럼 접근이 되는 것이다.

라고 이해함.

*/
