/*
place도, cut도 가능하고 place & cut을 다 할수도 있음

5 2 3이면, cut 1회, place 3회를 해야 함.
접근방식은, 2805번과 같이
정렬 -> 이분탐색이 맞을 것 같긴 한데
조금.. 복잡한 이분탐색이 될 것 같음.
일단 minimum은 젤 작은 블럭높이가 될거고
maximum은 젤 높은 블럭높이가 될거긴 함

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, B;
    int cost = 2147483647;
    int ansHeight = -1;
    cin >> N >> M >> B;
    vector<int> v;
    for (int i = 0; i < N * M; i++)
    {
        int block;
        cin >> block;
        v.push_back(block);
    }
    for (int height = 0; height <= 256; height++)
    {
        //printf("height [%d], ansHeight [%d], cost [%d]\n", height, ansHeight, cost);
        int costSum = 0;
        int remainingBlocks = B;
        for (int i = 0; i < v.size(); i++)
        {
            // place해야 하는 경우.
            if (v[i] - height < 0)
            {
                remainingBlocks -= (height - v[i]);
                costSum += (height - v[i]);
            }
            else if (v[i] - height > 0)
            {
                remainingBlocks += (v[i] - height);
                costSum += 2 * (v[i] - height);
            }
        }
        // 높이가 너무 낮음. place하기 힘듦.
        if (remainingBlocks < 0)
        {
        }
        else
        {
            // 현재의 케이스가 이전의 케이스보다 최적.
            if (costSum <= cost)
            {
                cost = costSum;
                ansHeight = height;
            }
        }
    }
    printf("%d %d\n", cost, ansHeight);
}