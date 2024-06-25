#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    bool asc = true, desc = true;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] < arr[i + 1])
            desc = false;
        else if (arr[i] > arr[i + 1])
            asc = false;
    }
    if (asc)
        cout << "ascending" << endl;
    else if (desc)
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;
}