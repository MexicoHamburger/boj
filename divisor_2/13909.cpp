#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans, i= 0;
    cin >> n;
    while (++i) {
        if (i * i <= n) {
            ans++;
        }
        else break;
    }
    cout << ans << endl;
}
