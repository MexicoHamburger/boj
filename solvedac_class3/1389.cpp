#include <bits/stdc++.h>
using namespace std;

int friends[101][101];
const int INF = 1e7;
void initGraph()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (i == j)
            {
                friends[i][j] = 0;
            }
            else
            {
                friends[i][j] = INF;
            }
        }
    }
}

void makeGraph(int M)
{
    for (int i = 0; i < M; i++)
    {
        int src, des;
        scanf("%d %d", &src, &des);
        friends[src][des] = 1;
        friends[des][src] = 1;
    }
}
int FloydWarshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int src = 1; src <= n; src++)
        {
            for (int des = 1; des <= n; des++)
            {
                friends[src][des] = min(friends[src][des], friends[src][k] + friends[k][des]);
            }
        }
    }

    // logger
    /*
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            printf("[%d] ", friends[i][j]);
        }
        printf("\n");
    }
    */
   
    int minKevinBacon = INF;
    int minPersonName = -1;
    for (int i = n; i >= 1; i--)
    {
        int kevinBaconSum = 0;
        for (int j = n; j >= 1; j--)
        {
            if (i != j)
            {
                kevinBaconSum += friends[i][j];
            }
        }
        if (kevinBaconSum <= minKevinBacon)
        {
            //printf("kevin Bacon updated. [%d] -> [%d] with [%d] [%d]\n", minPersonName, i, kevinBaconSum, minKevinBacon);
            minPersonName = i;
            minKevinBacon = kevinBaconSum;
        }
    }

    return minPersonName;
}
int main()
{
    int N, M;
    initGraph();

    cin >> N >> M;
    makeGraph(M);
    int smallest = FloydWarshall(N);
    cout << smallest << endl;
}