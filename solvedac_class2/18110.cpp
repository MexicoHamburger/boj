#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int roff = round(N * 0.15);
    for (int i = roff; i < N - roff; i++)
    {
        ans += v[i];
    }
    cout << (int)round((double)ans / (N - 2 * roff));
}