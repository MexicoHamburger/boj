#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    cout << arr[0] + arr[1] - arr[2] << endl;

    int digit = 0;
    int temp = arr[1];
    while (temp)
    {
        temp /= 10;
        digit++;
    }
    cout << arr[0] * int(pow(10,digit)) + arr[1] - arr[2] << endl;
}