/*
숫자가 10만개다. 브루트포싱할 수 없는 숫자다.
4 3 이라면 가능할까?
1, 2, 3, [4]
1, 2, [3]
가능하다

4 6이라면?
1, 2, 3, [4]
1, 2, 3, 5, [6]
가능하다

4 1이라면?
1, 2, 3, [4] ... 이럼 불가능할 것 처럼 보이지만,
진작에 2, 3이 pop되어 있던 상태라면, 충분히 가능하다.

가설을 세워보자.
1. increasing order면 항상 pop을 통해 만들 수 잇다.
2. decreasing order라면, pop target과 next target 사이에 아무 숫자도 없으면 pop이 가능하다.
가령, 4 1 이라면, 2와 3이 진즉 pop되어 사라진 상태면 가능하다.
하지만, 2와 3 중 무엇이라도 남아있다면, 불가능하다.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> targetq;
    stack<int> st;
    queue<char> op;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        targetq.push(t);
    }
    int prev = 0;
    while (targetq.empty() == false)
    {
        // 초기에는 prev = 0, next = q.front()
        // 그 후에는 갱신된 값이 prev, next = q.front()
        if (targetq.front() == prev)
        {
            // cout << "popping " << prev << endl;
            targetq.pop();
            st.pop();
            op.push('-');
        }
        else if (targetq.front() > prev)
        {
            prev++;
            st.push(prev);
            // cout << "pushing "<< prev << endl;
            op.push('+');
        }
        else if (targetq.front() < prev)
        {
            if (st.empty() || st.top() != targetq.front())
            {
                cout << "NO";
                return 0;
            }
            else
            {
                targetq.pop();
                st.pop();
                op.push('-');
            }
        }
    }
    while (op.empty() == false)
    {
        cout << op.front() << '\n';
        op.pop();
    }
}