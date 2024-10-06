#include <bits/stdc++.h>
using namespace std;

/*
1. 시작지점은 left = right = 0, 종료지점은 right = max
2. sliding window 기법을 이용
3. window 내의 원소가 1종류일 시 right++
4. window 내의 원소가 2종류일 시 right++
5. window 내의 원소가 3종류일 시 left++
*/

int main()
{
    int N, tmp;
    cin >> N;
    int *tanghulu = new int[N + 1];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        tanghulu[i] = tmp;
    }
    int left = 0;
    int right = 0;
    int ans = 0;
    int count = 1;
    unordered_map<int, int> m;
    set<int> s;
    m[tanghulu[0]]++;
    s.insert(tanghulu[0]);
    while (right < N)
    {
        count = s.size();
        // printf("%d %d %d\n", left, right, count);
        if (count == 1 || count == 2)
        {
            ans = max(ans, (right - left) + 1);
            right++;
            if (right < N)
            {
                m[tanghulu[right]]++;
                s.insert(tanghulu[right]);
            }
        }
        else if (count == 3)
        {
            if (m[tanghulu[left]] == 1)
            {
                m.erase(tanghulu[left]);
                s.erase(tanghulu[left]);
            }
            else
            {
                m[tanghulu[left]]--;
            }
            left++;
        }
    }
    cout << ans;
}