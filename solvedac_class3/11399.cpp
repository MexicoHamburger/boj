#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> ppl;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ppl.push_back(tmp);
    }
    sort(ppl.begin(), ppl.end());
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ppl[i];
        ans += sum;
    }
    cout << ans;
}