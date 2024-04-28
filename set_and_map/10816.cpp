#include <bits/stdc++.h>
using namespace std;

int main()
{
        
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec;
    map<int, int> item_count;
    int N, M, input;
    cin >> N;
    
    for (int i = 0 ; i < N ; i++) {
        cin >> input;
        vec.push_back(input);
    }
    cin >> M;
    sort(vec.begin(), vec.end());

    int prevIdx = 0;
    int prevVal = vec[0];
    for (int i = 0 ; i <= N ; i++) {
        if (i == N) {
            item_count[prevVal] = i - prevIdx;
            break;
        }
        if (prevVal != vec[i]) {
            item_count[prevVal] = i - prevIdx;
            prevVal = vec[i];
            prevIdx = i;
        }
    }
    int value;
    for (int i = 0 ; i < M ; i++) {
        cin >> value;
        printf("%d ", item_count[value]);
    }
}