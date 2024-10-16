#include <bits/stdc++.h>
using namespace std;

int main()
{
    int subin, bro;
    cin >> subin >> bro;

    int arr[100001] = {
        0,
    };
    int vis[100001] = {
        0,
    };

    queue<int> q;

    q.push(subin);
    vis[subin] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            subin = q.front();
            q.pop();
            if (subin == bro)
            {
                cout << cnt << endl;
                return 0;
            }

            if (subin != 0 && !vis[subin - 1])
            {
                //cout << "pushing " << subin - 1 << endl;
                q.push(subin - 1);
                vis[subin - 1] = true;
            }
            if (subin < 100000 && !vis[subin + 1])
            {
                //cout << "pushing " << subin + 1 << endl;
                q.push(subin + 1);
                vis[subin + 1] = true;
            }
            if (subin <= 50000 && !vis[subin * 2])
            {
                //cout << "pushing " << subin * 2 << endl;
                q.push(subin * 2);
                vis[subin * 2] = true;
            }
        }
        cnt++;
    }
    return 0;
}