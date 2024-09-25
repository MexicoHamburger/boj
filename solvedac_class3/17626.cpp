#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[50001];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 50000; i++)
    {
        dp[i] = 987654321;
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n];
}