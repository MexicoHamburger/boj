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

    int T, A, B, lcm;
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        cin >> A >> B;
        if (A < B) lcm = A*B / gcd(B,A);
        else lcm = A*B / gcd(A,B);
        cout << lcm << endl;
    }
}