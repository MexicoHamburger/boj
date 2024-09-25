#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int cnt = 0;
    while (k)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (coins[i] <= k)
            {
                cnt++;
                k -= coins[i];
                break;
            }
        }
    }
    cout << cnt;
}