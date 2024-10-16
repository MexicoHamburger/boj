#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
int dist[100][100];

void initDist()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i != j)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = 0;
            }
        }
    }
}

void floydWarshall(int N)
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val;
            scanf("%d", &val);
            if (val == 0)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = 1;
            }
        }
    }

    floydWarshall(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] < INF)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}