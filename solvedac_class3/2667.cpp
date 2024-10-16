#include <bits/stdc++.h>
using namespace std;
int town[30][30] = {
    0,
};

int vis[30][30] = {
    0,
};

queue<pair<int, int>> houseQ;
vector<int> houseCnt;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void findNeighborAndDisable(int i, int j)
{
    int cnt = 0;

    houseQ.push(pair(i, j));
    vis[i][j] = 1;

    while (!houseQ.empty())
    {
        int size = houseQ.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = houseQ.front();
            houseQ.pop();
            //cout << "POPPED " << "[" << p.first << "]" << " [" << p.second << "]" << endl;
            cnt++;
            for (int i = 0; i < 4; i++)
            {
                int nextY = p.first + dy[i];
                int nextX = p.second + dx[i];
                // cout << "checking " << nextY << " " << nextX << endl;
                if (town[nextY][nextX] && !vis[nextY][nextX])
                {
                    houseQ.push(pair(nextY, nextX));
                    town[nextY][nextX] = 0;
                    vis[nextY][nextX] = 1;
                }
            }
        }
    }
    houseCnt.push_back(cnt);
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char *line = new char[N + 1];
        scanf("%s", line);
        for (int j = 0; j < N; j++)
        {
            town[i + 1][j + 1] = (line[j] - '0');
        }
        delete[] line;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (town[i][j])
            {
                //cout << "---STARTING AT " << i << " " << j << endl;
                findNeighborAndDisable(i, j);
            }
        }
    }
    sort(houseCnt.begin(), houseCnt.end());
    cout << houseCnt.size() << endl;

    for (int i = 0; i < houseCnt.size(); i++)
    {
        cout << houseCnt[i] << endl;
    }
}