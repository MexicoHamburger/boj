#include <bits/stdc++.h>
using namespace std;
int gcd(int A, int B) {
    int r;
    while ( B != 0) {
        r = A % B;
        A = B;
        B = r;
    }
    return A;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> trees;
    for (int i = 0 ; i < t ; i++) {
        int pos;
        cin >> pos;
        trees.push_back(pos);
    }
    int ans = trees[1] - trees[0];
    for (int i = 0 ; i < t-1 ; i++) {
        ans = gcd(ans, (trees[i+1] - trees[i]));
    }
cout << ((*(trees.end()-1) - *trees.begin()) / ans) - trees.size() + 1;

}