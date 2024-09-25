#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 2);
    int prev = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        arr[i] = input + prev;
        prev = arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }
}