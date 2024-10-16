#include <bits/stdc++.h>
using namespace std;
/*
10 12 3 9
-> <1,1> <2,2> <3,3> .. <9,9> <10,10>, <1,11>, <2,12>, ...
<3,y>는 10n + 3번째 해일 것이고,
<x,9>는 12m + 9번째 해일 것이다.
즉 10n + 3 = 12m + 9가 되는 (m,n)의 쌍을 찾으면 된다. 단, n < 12, m < 10이 보장되어야 한다. (그 후는 세계의 멸망이 찾아오니까!)

일반화해보자.
M N x y에서,
Mn + x = Nm + y가 되는 (m,n)의 쌍을 찾으면 된다.
즉, n = (Nm + y - x) / M

Nm + y - x가 M으로 나눠떨어지는지 확인한다. m은 N보다 작아야 한다.
나눠떨어진다면, 나누면 그 값이 n이 된다.
*/

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int x, int y)
{
    return x*y / gcd(x,y);
}

void findCalendar(int M, int N, int x, int y)
{
    int apocalypse = lcm(M,N);
    for (int i = x ; i <= apocalypse ; i += M)
    {
        // 10, 12, 3, 9일때, 3, 13, 23, 33, 43, ...을 전부 비교해본다
        // 33 % 12 = 9고 9 = y니까 이 경우가 정답
        if (i % N == y)
        {
            cout << i << endl;
            return;
        }
        // 나머지가 0일수도 있다! 이 경우는 존재하지 않아야 하지만, y = N이라면 가능하다.
        else if (i % N == 0)
        {
            if (y == N)
            {
                cout << i << endl;
                return;
            }
        }
    }
    cout << "-1" << endl;
    return;
}
int main()
{
    int T;
    int M,N,x,y;
    cin >> T;
    for (int i = 0 ; i < T ; i++)
    {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        findCalendar(M,N,x,y);
    }
}