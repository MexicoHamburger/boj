#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll A, ll B) {
    ll r;
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

    ll A,B, lcm;
    cin >> A >> B;
    if (A < B) lcm = A*B / gcd(B,A);
    else lcm = A*B / gcd(A,B);
    cout << lcm << endl;
}