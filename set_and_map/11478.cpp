#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;
    set<string> answerset;
    for (int i = 1 ; i <= input.size() ; i++) {
        for (int j = 1 ; j <= input.size() ; j++) {
            answerset.insert(input.substr(i-1, j));
        }
    }
    cout << answerset.size() << endl;
}