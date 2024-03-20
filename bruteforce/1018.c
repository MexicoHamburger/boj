#include <stdio.h>

int main()
{
    char test1[8][8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };
    char test2[8][8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };
    int row, col;
    scanf("%d %d", &row, &col);
    char chess[51][51] = {0,};
    for (int i = 0 ; i < row ; i++) {
        for (int j = 0 ; j < col ; j++) {
            scanf(" %c", &chess[i][j]);
        }
    }
    int rowdiff = row - 8;
    int coldiff = col - 8;
    int ans = 102931723;
    int tmp1, tmp2;
    for (int i = 0 ; i <= rowdiff ; i++) {
        for (int j = 0 ; j <= coldiff ; j++) {
            tmp1 = 0;
            tmp2 = 0;
            for (int k = 0 ; k < 8 ; k++) {
                for (int l = 0 ; l < 8 ; l++) {
                    if (test1[k][l] != chess[k+i][l+j]) {
                        //printf("test1[%d][%d] : %c, chess[%d][%d] : %c\n", k, l, test1[k][l], k+i, l+j, chess[k+i][l+j]);
                        tmp1++;
                    }
                    if (test2[k][l] != chess[k+i][l+j]) {
                        tmp2++;
                    }
                }
            }
            //printf("tmp1 %d tmp2 %d\n", tmp1, tmp2);
            ans = tmp1 < ans ? tmp1 : ans;
            ans = tmp2 < ans ? tmp2 : ans;

        }
    }
    printf("%d", ans);
}