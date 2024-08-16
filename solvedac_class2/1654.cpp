#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll K, N;
    cin >> K >> N;

    vector<int> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
    }

    ll low = 1; // 최소 길이는 1로 설정
    ll high = *max_element(v.begin(), v.end()); // 최대 길이는 가장 긴 랜선의 길이로 설정
    ll result = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        long long cnt = 0;

        // mid 길이로 만들 수 있는 랜선의 수 계산
        for (int i = 0; i < K; i++) {
            cnt += v[i] / mid;
        }

        // cnt가 N 이상이면 더 긴 랜선이 가능한지 확인
        if (cnt >= N) {
            result = mid; // 가능한 값이므로 결과에 저장
            low = mid + 1; // 더 긴 랜선이 가능한지 확인하기 위해 범위를 높임
        } else {
            high = mid - 1; // 랜선의 길이를 줄여야 함
        }
    }

    cout << result << endl;
}
