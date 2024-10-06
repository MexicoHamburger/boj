#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    int N, cmd;
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        scanf("%d", &cmd);
        if (cmd == 0) {
            if (pq.empty()) {
                printf("0\n");
            }
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else {
            pq.push(cmd);
        }
    }
}