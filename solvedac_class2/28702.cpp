#include <bits/stdc++.h>
using namespace std;

string ret(int n)
{
    if (n % 3 == 0 && n % 5 == 0)
    {
        return "FizzBuzz";
    }
    else if (n % 3 == 0)
    {
        return "Fizz";
    }
    else if (n % 5 == 0)
    {
        return "Buzz";
    }
    else
    {
        return to_string(n);
    }
}
int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (isdigit(a[0]))
    {
        ans = stoi(a) + 3;
    }
    else if (isdigit(b[0]))
    {
        ans = stoi(b) + 2;
    }
    else if (isdigit(c[0]))
    {
        ans = stoi(c) + 1;
    }
    cout << ret(ans);
}