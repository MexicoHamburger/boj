#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec;
    int n, order, val;
    cin >> n;
    while (n--) {
        cin >> order;
        switch(order) {
            case 1 : {
                cin >> val;
                vec.push_back(val);
                break;
            }
            case 2 : {
                if (vec.size() == 0) {
                    cout << "-1\n";
                } else {
                    cout << vec[vec.size()-1] << "\n";
                    vec.pop_back();
                }
                break;
            }
            case 3 : {
                cout << vec.size() << "\n";
                break;
            }
            case 4 : {
                if (vec.size() == 0) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
                break;
            }
            case 5 : {
                if (vec.size() == 0) {
                    cout << "-1\n";
                } else {
                    cout << vec[vec.size()-1] << "\n";
                }
                break;
            }
            default : break;
        }
    }
}
