#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int tc;
    scanf("%d", &tc);
    
    for (int i = 1 ; i <= tc ; i++) {
        int qt = 0, dm = 0, nk = 0, pn = 0;
        int money;
        scanf("%d", &money);
        while (money != 0) {
            while (money - 25 * qt >= 0) {
                qt++;
            }
            qt--;
            money -= 25*qt;

            while (money - 10 * dm >= 0) {
                dm++;
            }
            dm--;
            money -= 10*dm;

            while (money - 5 * nk >= 0) {
                nk++;
            }
            nk--;
            money -= 5 * nk;

            while (money - pn >= 0) {
                pn++;
            }
            pn--;
            money -= pn;

        }
        printf("%d %d %d %d\n", qt, dm, nk, pn);
    }
}
