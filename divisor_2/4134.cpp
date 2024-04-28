#include <bits/stdc++.h>
using namespace std;

bool isPrime(unsigned int n) {
    for (unsigned int i = 2 ; i <= sqrt(n) ; i++) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}
unsigned int findPrime(unsigned int n) {
    while(1) {
        if (isPrime(n)) {
            return n;
        } else {
            n++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0 ; i < t ; i++) {
        unsigned int n;
        cin >> n;
        if (n == 0 || n == 1) {
            cout << "2" << endl;
            continue;
        }
        cout << findPrime(n) << endl;
    }
}