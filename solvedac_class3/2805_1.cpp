#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<int> v;
    int N, M, tree;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tree);
        v.push_back(tree);
    }
    sort(v.begin(), v.end());

    int start = 0;
    int end = v[v.size() - 1];

    int max = 0;
    while (start <= end)
    {
        int cut = (start + end) / 2;
        ll sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > cut)
            {
                sum += v[i] - cut;
            }
        }
        if (sum >= M)
        {
            max = cut;
            start = cut + 1;
        }
        else
        {
            end = cut - 1;
        }
    }
    printf("%d", max);
}