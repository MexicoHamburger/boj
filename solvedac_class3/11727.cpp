#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[50];
    dp[1] = 1;
    dp[2] = 4;
    for (int i = 3 ; i <= 1000 ; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    cout << dp[n];
}