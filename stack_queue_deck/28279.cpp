#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, comm, val;
    deque<int> deck;
    cin >> n;
    for (int i = 0 ; i < n ; i++) 
    {
        cin >> comm;
        switch(comm) {
            case 1: {
                cin >> val;
                deck.push_front(val);
                break;
            }
            case 2: {
                cin >> val;
                deck.push_back(val);
                break;
            }
            case 3: {
                if (deck.empty()) {
                    cout << "-1\n";
                } else {
                    cout << deck.front() << "\n";
                    deck.pop_front();
                }
                break;
            }
            case 4: {
                if (deck.empty()) {
                    cout << "-1\n";
                } else {
                    cout << deck.back() << "\n";
                    deck.pop_back();
                }
                break;
            }
            case 5: {
                cout << deck.size() << "\n";
                break;
            }
            case 6: {
                if (deck.empty()) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
                break;
            }
            case 7: {
                if (deck.empty()) {
                    cout << "-1\n";
                } else {
                    cout << deck.front() << "\n";
                }
                break;
            }
            case 8: {
                if (deck.empty()) {
                    cout << "-1\n";
                } else {
                    cout << deck.back() << "\n";
                }
                break;
            }
            default: break;
        }
    }
    return 0;
}
