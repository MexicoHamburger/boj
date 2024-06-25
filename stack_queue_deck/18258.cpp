#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> vec;

    int t, toPush, printVal;
    string command;
    cin >> t;

    for (int i = 0 ; i < t ; i++) {
        cin >> command;
        if (command == "push") {
            cin >> toPush;
            vec.push(toPush);
        }
        else if (command == "front") {
            if (vec.size() == 0) {
                cout << "-1\n";
                continue;
            }
            cout << vec.front() << "\n";
        }
        else if (command == "back") {
            if (vec.size() == 0) {
                cout << "-1\n";
                continue;
            }
            cout << vec.back() << "\n";
        }
        else if (command == "empty") {
            if (vec.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        else if (command == "size") {
            cout << vec.size() << "\n";
        }
        else if (command == "pop") {
            if (vec.empty()) {
                cout << "-1\n";
            } else {
                cout << vec.front() << "\n";
                vec.pop();
            }
        }
        
    }
    return 0;
    
}
