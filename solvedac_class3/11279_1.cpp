#include <bits/stdc++.h>
using namespace std;

int maxheap[100001] = {
    -1,
};
int cnt = -1;

void swap(int src, int des)
{
    int temp = maxheap[src];
    maxheap[src] = maxheap[des];
    maxheap[des] = temp;
}

void insert(int data)
{
    maxheap[++cnt] = data;
    int cur = cnt;

    while (cur != 0)
    {
        int parent = (cur - 1) / 2;
        if (maxheap[parent] > maxheap[cur])
        {
            break;
        }
        else
        {
            swap(parent, cur);
            cur = parent;
        }
    }
}

int remove()
{
    if (cnt == -1) {
        return 0;
    }
    int ret = maxheap[0];
    maxheap[0] = maxheap[cnt];
    maxheap[cnt] = -1;
    cnt--;
    int cur = 0;

    while (cur < (cnt+1) / 2)
    {
        int leftchild = cur*2 + 1;
        int rightchild = cur*2 + 2;
        
        int biggerIdx = maxheap[leftchild] > maxheap[rightchild] ? leftchild : rightchild;
        if (maxheap[biggerIdx] < maxheap[cur]) {
            break;
        }
        else {
            swap(biggerIdx, cur);
            cur = biggerIdx;
        }
    }
    return ret;
}
int main()
{
    int N, cmd;
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        scanf("%d", &cmd);
        if (cmd == 0) {
            printf("%d\n", remove());
        }
        else {
            insert(cmd);
        }
    }
}