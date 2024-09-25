#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<string, string> mp;
    for (int i = 0 ; i < n ; i++)
    {
        string site, password;
        cin >> site >> password;
        mp[site] = password;
    }
    for (int i = 0 ; i < m ; i++)
    {
        string site;
        cin >> site;
        cout << mp[site] << '\n';
    }
}