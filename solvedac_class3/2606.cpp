#include <bits/stdc++.h>
using namespace std;

int visited[101] = {
    0,
};

int arr[101][101] = {
    0,
};

void dfs(int nodenum)
{
    visited[nodenum] = 1;
    for (int i = 1; i < 101; i++)
    {
        if (arr[nodenum][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int cmps, net;
    cin >> cmps >> net;

    for (int i = 0; i < net; i++)
    {
        int src, des;
        cin >> src >> des;
        arr[src][des] = 1;
        arr[des][src] = 1;
    }
    // 2차원배열 안에 감염된 그래프가 그려져 있는데, 연결된 노드가 몇개인지 어떻게 파악할래?
    // dfs나 bfs 하면 될거같은데 dfs, bfs가 기억이 안남 ㅋㅋ
    // dfs로 해보자

    dfs(1);

    int cnt = 0;
    for (int i = 1; i < 101; i++)
    {
        if (visited[i] == 1)
        {
            cnt++;
        }
    }
    cout << cnt - 1;
}