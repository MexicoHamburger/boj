/*
n = 5면 1,3,5,7,9,7,5,3,1개의 별을 찍어야 함
먼저 idx에 따라 몇개의 별이 찍히는지를 체크하고 그걸 이용해서 뭔갈 만들면 될듯 하다
*/

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1 ; i < N * 2 ; i++) {

        int num = i;
        if (i > N) num = 2*N - i;

        for (int j = 1 ; j <= ((2*N-1)- (2*num-1)) / 2 ; j++) printf(" ");
        for (int j = 1 ; j <= 2*num-1 ; j++) printf("*");
        printf("\n");
    }    
}