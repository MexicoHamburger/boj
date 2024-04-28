#include <bits/stdc++.h>
using namespace std;

vector<bool> che(1000001, true);
unordered_set<int> sosu;
int findAnswer(int n) {
    int ans = 0;
    for (int data : sosu) {
        if (sosu.find(n-data) != sosu.end()) {
            ans++;
        }
    }

    if (ans %2 == 1) ans++;     //[5][5]같은 케이스가 있는 경우를 보정
    return ans;
}

void erathos(int n) {
    int ans = 0;
    che[0] = che[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (che[i]) {
            for (int j = i + i; j <= n; j += i) {
                che[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (che[i]) sosu.insert(i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;
    erathos(1000000);
    while (T--) {
        cin >> n;
        cout << findAnswer(n) / 2 << endl;
    }
}
