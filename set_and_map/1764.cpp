#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    set<string> dbj;
    vector<string> answer;
    int dbjcount = 0;

    for (int i = 0 ; i < N ; i++) {
        string input;
        cin >> input;
        dbj.insert(input);

    }
    
    for (int i = 0 ; i < M ; i++) {
        string input;
        cin >> input;
        if (dbj.find(input) != dbj.end()) {
            answer.push_back(input);
            dbjcount++;
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (string elem : answer) {
        cout << elem << "\n";
    }
}