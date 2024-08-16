#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L;
    string input;

    int r = 31;
    int M = 1234567891;
    int ans = 0;
    long long r_power = 1; // r^i 값을 저장

    cin >> L >> input;

    for (int i = 0; i < L; i++) {
        // ans에 각 문자에 해당하는 값을 추가하고 모듈러 연산
        ans = (ans + (input[i] - 'a' + 1) * r_power) % M;
        
        // 다음 루프를 위해 r^i 값을 r^(i+1) 값으로 갱신하고 모듈러 연산
        r_power = (r_power * r) % M;
    }
    
    cout << ans;
}