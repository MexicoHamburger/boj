#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i += 5)
    {
        int tmp = 0;
        int idx = i;
        while (idx % 5 == 0)
        {
            idx /= 5;
            tmp++;
        }
        cnt += tmp;
    }
    cout << cnt;

}