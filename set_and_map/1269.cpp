#include <bits/stdc++.h>
using namespace std;

map<int, int> inputHandle (int n) {
    map<int, int> tMap;
    for (int i = 0 ; i < n ; i++) {
        int val;
        cin >> val;
        tMap[val] = 1;
    }
    return tMap;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    int ans = 0;
    cin >> A >> B;
    map<int, int> aSet = inputHandle(A);
    map<int, int> bSet = inputHandle(B);

    for (const auto& pair : aSet) {
        if (bSet[pair.first] == 0) ans++;
    }
    for (const auto& pair : bSet) {
        if (aSet[pair.first] == 0) ans++;
    }

    cout << ans << endl;
}