#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        q.push(i);
    }

    for (int i = 0 ; i < n-1 ; i++) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}
