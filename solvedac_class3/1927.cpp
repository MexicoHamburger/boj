#include <bits/stdc++.h>
using namespace std;

int minheap[100001] = {
    -1,
};
int cnt = -1;

int isLeaf(int idx)
{
    return idx >= ((cnt + 1) / 2);
}
void swap(int parent, int child)
{
    int temp = minheap[parent];
    minheap[parent] = minheap[child];
    minheap[child] = temp;
}

void logger()
{
    for (int i = 0; i <= cnt; i++)
    {
        printf("[%d] ", minheap[i]);
    }
    printf("\n");
}
void insert(int data)
{
    cnt++;
    minheap[cnt] = data;
    int child = cnt;
    while (child)
    {
        int parent = (child - 1) / 2;
        if (minheap[parent] > minheap[child])
        {
            swap(parent, child);
            child = parent;
        }
        else
        {
            break;
        }
    }
    // printf("insert complete with cnt %d\n", cnt);
    // logger();
}

void remove()
{
    if (cnt == -1)
    {
        printf("0\n");
        return;
    }
    printf("%d\n", minheap[0]);
    minheap[0] = minheap[cnt];
    minheap[cnt] = -1;
    cnt--;

    int parent = 0;
    while (1)
    {
        //printf("<<%d %d>>\n", parent, cnt);
        if (isLeaf(parent))
        {
            //printf("<%d %d>\n", parent, cnt);
            break;
        }
        int leftchild = parent * 2 + 1;
        int rightchild = parent * 2 + 2;
        if (rightchild > cnt) // left child만 존재하는 경우
        {
            if (minheap[leftchild] <= minheap[parent])
            {
                //logger();
                //printf("i am %d, swapping %d, %d\n", parent, minheap[leftchild], minheap[parent]);
                swap(leftchild, parent);
                parent = leftchild;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (minheap[leftchild] < minheap[rightchild])
            {
                if (minheap[leftchild] <= minheap[parent])
                {
                    //printf("2 - swapping %d, %d\n", minheap[leftchild], minheap[parent]);
                    swap(leftchild, parent);
                    parent = leftchild;
                }
                else
                {
                    break;
                }
            }
            else if (minheap[rightchild] <= minheap[leftchild])
            {
                if (minheap[rightchild] <= minheap[parent])
                {
                    //printf("3 - swapping %d, %d\n", minheap[rightchild], minheap[parent]);
                    swap(rightchild, parent);
                    parent = rightchild;
                }
                else
                {
                    break;
                }
            }
        }
    }
    //printf("remove complete with cnt %d\n", cnt);
    //logger();
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
        {
            remove();
        }
        else
        {
            insert(num);
        }
    }
}