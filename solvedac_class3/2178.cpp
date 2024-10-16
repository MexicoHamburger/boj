#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    int N, M;
    cin >> N >> M;
    int arr[101][101] = {0,};
    int vis[101][101] = {0,};
    for (int i = 1; i <= N; i++)
    {
        char *mapInfo = new char[M];
        scanf("%s", mapInfo);
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = (mapInfo[j - 1] - '0');
        }
    }

    queue<pair<int, int>> q;
    q.push(pair(1, 1));
    vis[1][1] = 1;
    int cnt = 0;

    while (!q.empty())
    {
        cnt++;
        int size = q.size();
        // cout << "[" << cnt << "]" << endl;
        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            if (p.first == N && p.second == M)
            {
                cout << cnt << endl;
                return 0;
            }
            // cout << "now at " << p.first << " " << p.second << endl;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextCoordX = p.second + dy[i];
                int nextCoordY = p.first + dx[i];
                if (arr[nextCoordY][nextCoordX] && !vis[nextCoordY][nextCoordX])
                {
                    q.push(pair(nextCoordY, nextCoordX));
                    vis[nextCoordY][nextCoordX] = 1;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}