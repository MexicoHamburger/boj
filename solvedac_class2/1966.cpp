#include <bits/stdc++.h>
using namespace std;

int findMax(queue<int> q)
{
    if (q.empty())
    {
        throw runtime_error("Queue is empty");
    }

    int maxVal = q.front();

    while (!q.empty())
    {
        if (q.front() > maxVal)
        {
            maxVal = q.front();
        }
        q.pop();
    }

    return maxVal;
}

int main()
{
    int N;
    int cnt, target;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cnt >> target;
        queue<int> q;
        for (int j = 0; j < cnt; j++)
        {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        /*
        while (target is not popped)
        {
            if target == 0
                if q.front() == max
                    finish while loop
                else
                    move target to back
                    change target to last index
                    continue while loop

            else if target != 0
                if q.front() == max
                    pop front
                    increase count
                    decrease target
                else
                    move front to back
                    decrease target
        }
        */
        int isPopped = 0;
        int ans = 0;
        while (!isPopped)
        {
            int max = findMax(q);
            if (target == 0)
            {
                if (q.front() == max)
                {
                    isPopped = 1;
                    ans++;
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                    target = q.size() - 1;
                }
            }
            else
            {
                if (q.front() == max)
                {
                    q.pop();
                    ans++;
                    target--;
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                    target--;
                }
            }
        }
        cout << ans << '\n';
    }
}