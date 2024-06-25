#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, comm;
    cin >> n;
    vector<int> vec;
    vector<int> balloons;
    for (int i = 1 ; i <= n ; i++) {
        vec.push_back(i);
    }

    for (int i = 0 ; i < n ; i++) {
        cin >> balloons[i];
    }
    int idx = 0;
    int iter = n;
    for (int i = 0 ; i < iter ; i++) {
        idx += balloons[i];

        if (idx < 0) {
            while (idx < 0) {
                idx += n;
            }
            
        }
        else if (idx >= n) {
            while (idx >= n) {
                idx -= n;
            }
        }

        n--;
    }
    return 0;
}
