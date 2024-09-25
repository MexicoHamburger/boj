#include <bits/stdc++.h>
using namespace std;

int cab[50][50] = {0,};
void dfs(int x, int y)
{
    if (cab[x][y] == 0)
    {
        return;
    }
    cab[x][y] = 0;
    if (x > 0)
    {
        dfs(x-1, y);
    }
    if (y > 0)
    {
        dfs(x, y-1);
    }
    if (x < 50)
    {
        dfs(x+1, y);
    }
    if (y < 50)
    {
        dfs(x, y+1);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int tv1 = 0 ; tv1 < t ; tv1++)
    {
        memset(cab, 0, sizeof(cab));
        int m, n, k;
        int cnt = 0;
        cin >> m >> n >> k;
        for (int tv2 = 0 ; tv2 < k ; tv2++)
        {
            int x, y;
            cin >> x >> y;
            cab[y][x] = 1;
        }
        
        for (int tv3 = 0 ; tv3 < n ; tv3++)
        {
            for (int tv4 = 0 ; tv4 < m ; tv4++)
            {
                if (cab[tv3][tv4])
                {
                    dfs(tv3, tv4);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}