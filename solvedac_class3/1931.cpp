#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, start, end;
    vector <pair<int, int>> v;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d %d", &start, &end);
        v.push_back(pair(end, start));
    }
    sort(v.begin(), v.end());
    /*
    for (const auto& p : v)
    {
        cout << p.first << ": " << p.second << endl;
    }
    */
    int cnt = 0;
    int curEndingTime = v[0].first;
    cnt++;
    for (int i = 1 ; i < n ; i++)
    {
        if (v[i].second >= curEndingTime)
        {
            cnt++;
            curEndingTime = v[i].first;
        }
    }
    cout << cnt << endl;
}