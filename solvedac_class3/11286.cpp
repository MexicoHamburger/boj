#include <bits/stdc++.h>
using namespace std;

typedef pair<int, bool> node;

struct Compare
{
    bool operator()(node a, node b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }
};

priority_queue<node, vector<node>, Compare> pq;

void printValue(int val)
{
    if (pq.size() == 0)
    {
        printf("0\n");
    }
    else
    {
        node n = pq.top();
        pq.pop();
        if (n.second == true)
        {
            printf("%d\n", n.first);
        }
        else
        {
            printf("%d\n", -1 * n.first);
        }
    }
}

void insertValue(int val)
{
    if (val < 0)
    {
        node n = make_pair(-val, false);
        pq.push(n);
    }
    else
    {
        node n = make_pair(val, true);
        pq.push(n);
    }
}

int main()
{
    priority_queue<node, vector<node>, Compare> pq;
    int N, val;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &val);
        if (val == 0)
        {
            printValue(val);
        }
        else
        {
            insertValue(val);
        }
    }
}