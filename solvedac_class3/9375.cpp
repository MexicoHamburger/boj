#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        map<string, set<string>> clothes;
        set<string> cType;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string name, type;
            cin >> name >> type;
            cType.insert(type);
            clothes[type].insert(name);
        }
        int ans = 1;
        for (auto i = cType.begin(); i != cType.end(); i++)
        {
            ans *= clothes[*i].size() + 1;
        }
        cout << ans - 1 << '\n';
    }
}