#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int size[6];
    int T, P;
    cin >> N;
    for (int i = 0 ; i < 6 ; i++) {
        cin >> size[i];
    }
    cin >> T >> P;
    int shirts = 0;
    for (int i = 0 ; i < 6 ; i++) {
        if (size[i] == 0) {
            continue;
        }
        if (size[i] % T == 0) {
            shirts += size[i] / T;
            continue;
        }
        shirts += (size[i] / T) + 1;
    }
    cout << shirts << endl;
    cout << N / P << " " << N % P << endl;
}