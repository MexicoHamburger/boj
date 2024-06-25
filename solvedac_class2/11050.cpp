#include <bits/stdc++.h>
using namespace std;

int fact(int a) {
    int ret = 1;
    while (a) {
        ret *= a;
        a--;
    }
    return ret;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << (fact(n)) / ((fact(k)) * (fact(n-k)));
}