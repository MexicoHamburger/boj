#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int maze[1000][1000] = {
    0,
};
int vis[1000][1000] = {
    0,
};
int ans[1000][1000] = {
    0,
};

void bfs(int start_i, int start_j)
{
    int cnt = 0;

    ans[start_i][start_j] = cnt;
    vis[start_i][start_j] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(start_i, start_j));

    while (!q.empty())
    {
        cnt++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> coord = q.front();
            q.pop();
            //cout << "Coord : " << coord.first << " , " << coord.second << " with cnt : " << cnt << endl;

            for (int i = 0; i < 4; i++)
            {
                int nextY = coord.first + dx[i];
                int nextX = coord.second + dy[i];
                if ((nextX >= 0) && (nextY >= 0) && (nextX < 1000) && (nextY < 1000) && (maze[nextY][nextX] == 1) && (vis[nextY][nextX] == 0))
                {
                    //cout << "nextY : " << nextY << ", nextX : " << nextX << endl;
                    vis[nextY][nextX] = 1;
                    ans[nextY][nextX] = cnt;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
}

void couldntVisit()
{
    for (int i = 0 ; i < 1000 ; i++)
    {
        for (int j = 0 ; j < 1000 ; j++)
        {
            if (maze[i][j] != 0 && vis[i][j] == 0)
            {
                ans[i][j] = -1;
            }
        }
    }
}
int main()
{
    int n, m, val;
    pair<int, int> des;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &val);
            if (val == 2)
            {
                des.first = i;
                des.second = j;
            }
            maze[i][j] = val;
        }
    }

    bfs(des.first, des.second);
    couldntVisit();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}