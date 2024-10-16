#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    int answerCnt = 0;
    // cout << "----STARTING----" << endl;
    // cout << S << " => " << targetIOI << endl;

    for (int i = 0; i < M; i++)
    {
        int OICnt = 0;
        if (S[i] == 'I')
        {
            while (i + 2 < M && S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                OICnt++;
                if (OICnt == N)
                {
                    //cout << "answerCnt : " << answerCnt << ", i : " << i << endl;
                    answerCnt++;
                    OICnt--;
                }
                i += 2;
            }
        }
    }
    cout << answerCnt << endl;
}
