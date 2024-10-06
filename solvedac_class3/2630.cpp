#include <bits/stdc++.h>
using namespace std;

int paper[128][128] = {
    0,
};

struct coord
{
    int x, y;
};

struct blocks
{
    coord coords;
    int length;
};

void logger(blocks b) {
    cout << "(" << b.coords.y << "," << b.coords.x << ") , " << b.length << endl; 
}
int main()
{
    vector<blocks> v; // vector에 저장되는 형태는 ((0,0), 8)같은 형태. 의미는 (0,0)부터 시작하는 8 by 8 chunk라는 뜻
    vector<blocks> perfectBlue;
    vector<blocks> perfectWhite;

    int length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
    coord c;
    c.x = 0;
    c.y = 0;
    blocks b;
    b.coords = c;
    b.length = length;
    v.push_back(b);

    while (!v.empty())
    {
        blocks b = v.back();
        v.pop_back();
        int initColor = -1;
        int shouldEscape = 0;
        for (int i = b.coords.y; i < b.coords.y + b.length; i++)
        {
            if (shouldEscape)
            {
                break;
            }
            for (int j = b.coords.x; j < b.coords.x + b.length; j++)
            {
                if (initColor == -1)
                {
                    initColor = paper[i][j];
                    //cout << i << " " << j << " is " << initColor << endl;
                }
                else if (initColor == 0)
                {
                    if (paper[i][j] == 1)
                    {
                        //logger(b);
                        shouldEscape = 1;
                        blocks b1, b2, b3, b4;
                        b1.coords = b2.coords = b3.coords = b4.coords = b.coords;
                        b2.coords.x = b.coords.x + b.length / 2;
                        b3.coords.y = b.coords.y + b.length / 2;
                        b4.coords.x = b2.coords.x;
                        b4.coords.y = b3.coords.y;
                        b1.length = b2.length = b3.length = b4.length = b.length / 2;
                        v.push_back(b1);
                        v.push_back(b2);
                        v.push_back(b3);
                        v.push_back(b4);
                        break;
                    }
                }
                else if (initColor == 1)
                {
                    if (paper[i][j] == 0)
                    {
                        shouldEscape = 1;
                        blocks b1, b2, b3, b4;
                        b1.coords = b2.coords = b3.coords = b4.coords = b.coords;
                        b2.coords.x = b.coords.x + b.length / 2;
                        b3.coords.y = b.coords.y + b.length / 2;
                        b4.coords.x = b2.coords.x;
                        b4.coords.y = b3.coords.y;
                        b1.length = b2.length = b3.length = b4.length = b.length / 2;
                        v.push_back(b1);
                        v.push_back(b2);
                        v.push_back(b3);
                        v.push_back(b4);
                        break;
                    }
                }
            }
        }
        if (!shouldEscape)
        {
            if (initColor)
            {
                perfectBlue.push_back(b);
            }
            else
            {
                perfectWhite.push_back(b);
            }
        }
    }
    cout << perfectWhite.size() << endl;
    cout << perfectBlue.size() << endl;
}