#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1;
    vector<int> v2;

    int t, val;
    cin >> t;
    for (int i = 0 ; i < t ; i++) {
        cin >> val;
        v1.push_back(val);
    }
    int turn = 1;

    for (int i = 0 ; i < t*2 ; i++) {
        if (v1.size() != 0 && turn == v1.front()) {
            //printf("Case 1 with t %d\n", i);
            v1.erase(v1.begin());
            turn++;
            continue;
        }
        if (v2.size() != 0 && turn == v2.back()) {
            //printf("case 2 with t %d\n", i);
            v2.erase(v2.end()-1);
            turn++;
            continue;
        }
        else if (v1.size() != 0 && turn != v1.front()) {
            //printf("case 3 with t %d\n", i);
            v2.push_back(v1.front());
            v1.erase(v1.begin());
            continue;
        }
    }
    if (v1.size() != 0 || v2.size() != 0) {
        cout << "Sad" << endl;
        return 0;
    }
    cout << "Nice" << endl;
    return 0;
    
}
