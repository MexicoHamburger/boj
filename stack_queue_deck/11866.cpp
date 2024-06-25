#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 1 ; i <= n ; i++) {
        vec.push_back(i);
    }
    cout << "<";
    int idx = 0;
    int iter =  n;
    for (int i = 0 ; i < iter ; i++) {
        idx = (idx + k - 1)%n;
        if (vec.size() == 1) {
            cout << *(vec.begin() + idx) << ">";
            vec.erase(vec.begin() + idx);
        }
        else {
            cout << *(vec.begin() + idx) << ", ";
            vec.erase(vec.begin() + idx);
        }
        n -= 1;
    }
    return 0;
}
