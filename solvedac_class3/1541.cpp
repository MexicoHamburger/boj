#include <bits/stdc++.h>
using namespace std;

/*
10 - 20 + 30 + 40 - 50 - 60이라고 해보자.
-가 나오면, 다음 -가 나올 때 까지 묶어주면 된다.
10 - (20 + 30 + 40) - 50 - 60

처음부터 읽는다고 할 때,
1 0 - 2 0 + 3 0 + 4 0 - 5 0 - 6 0 인데,

필요한 함수는 [1 0]을 int 10으로 해석해줄 parser

*/

int parser(string s)
{
    int t = 1;
    int ret = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ret += ((s[i] - 48) * t);
        t *= 10;
    }
    return ret;
}

int evaluator(string s)
{
    int src = 0;
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            ret += parser(s.substr(src, (i - src)));
            src = i + 1;
        }
    }
    ret += parser(s.substr(src, (s.length() - src)));
    return ret;
}

int main()
{
    string s;
    cin >> s;
    int src = 0;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            if (cnt == 0)
            {
                ans += evaluator(s.substr(src, i - src));
            }
            else
            {
                ans -= evaluator(s.substr(src, i - src));
            }
            src = i + 1;
            cnt++;
        }
    }
    if (cnt == 0)
    {
        ans += evaluator(s.substr(src, (s.length() - src)));
    }
    else
    {
        ans -= evaluator(s.substr(src, (s.length() - src)));
    }

    std::cout << ans << endl;
}