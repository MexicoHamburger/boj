#include <bits/stdc++.h>
using namespace std;
int gcd(int A, int B) {
    int r;
    while ( B != 0) {
        r = A % B;
        A = B;
        B = r;
    }
    return A;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int bj1, bm1, bj2, bm2;
    cin >> bj1 >> bm1 >> bj2 >> bm2;
    int bj = bj1 * bm2 + bj2 * bm1;
    int bm = bm1 * bm2;
    if (bj < bm) {
        cout << bj/gcd(bj, bm) << " " << bm/gcd(bj,bm);
    } else {
        cout << bj/gcd(bm,bj) << " " << bm/gcd(bm,bj);
    }
}