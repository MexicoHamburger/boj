#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    3+1
    4+1
    5+2
    7+2
    9+3
    12+4
    16+5
    21+7
    28+9 ..

    1 1 1 2 2 3 (prev + arr[0]) 4 (prev + arr[1]) 5 (prev + arr[2]) 7 (prev + arr[3]) 9 (prev + arr[4]) ..
    */
    int T;
    cin >> T;
    long long int arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for (int i = 6; i <= 100; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        cout << arr[N] << endl;
    }
}