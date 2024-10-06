#include <bits/stdc++.h>
using namespace std;

int campus[602][602];
int visited[602][602] = {
    0,
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int pplMet = 0;
// wall : -1, space : 0, person : 1

void initCampus()
{
    for (int i = 0; i < 602; ++i)
    {
        for (int j = 0; j < 602; ++j)
        {
            campus[i][j] = -1;
        }
    }
}
void makeMap(int N, int M, int *n, int *m)
{
    char mapTemp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &mapTemp);
            if (mapTemp == 'O')
            {
                campus[i][j] = 0;
            }
            else if (mapTemp == 'P')
            {
                campus[i][j] = 1;
            }
            else if (mapTemp == 'I')
            {
                campus[i][j] = 0;
                *n = i;
                *m = j;
            }
        }
    }
}

void DFS(int posN, int posM)
{
    // 1. set curPos as visited
    // 2. search L,R,U,D
    // 3. if found person, increase count and set him as wall
    // 4. if not visited / available, then go search.
    visited[posN][posM] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextN = posN + dx[i];
        int nextM = posM + dy[i];
        if (nextN >= 0 && nextM >= 0 && nextN < 602 && nextM < 602)
        {
            if (campus[nextN][nextM] == 1)
            {
                campus[nextN][nextM] = 0;
                pplMet++;
                DFS(nextN, nextM);
            }
            else if (campus[nextN][nextM] == 0 && visited[nextN][nextM] == 0)
            {
                // printf("now %d %d, going to %d %d\n", posN, posM, nextN, nextM);
                DFS(nextN, nextM);
            }
        }
    }
}
int main()
{
    int N, M, mapTemp, posN, posM;
    cin >> N >> M;
    initCampus();
    makeMap(N, M, &posN, &posM);
    // cout << "starting with " << posN << " " << posM << endl;
    DFS(posN, posM);

    if (pplMet == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << pplMet;
    }
}