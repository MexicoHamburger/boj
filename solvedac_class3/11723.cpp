#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int bit = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "add")
        {
            int num;
            cin >> num;
            bit |= (1 << (num-1));
        }
        else if (cmd == "remove")
        {
            int num;
            cin >> num;
            bit &= ~(1 << (num-1));
        }
        else if (cmd == "check")
        {
            int num;
            cin >> num;
            if (bit & (1 << (num-1)))
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "toggle")
        {
            int num;
            cin >> num;
            bit ^= (1 << (num-1));
        }
        else if (cmd == "all")
        {
            bit = 0b11111111111111111111;
        }
        else if (cmd == "empty")
        {
            bit = 0;
        }
    }
}