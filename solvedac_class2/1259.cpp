#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input;
    cin >> input;
    string i_tostr;
    while (input)
    {
        i_tostr = to_string(input);
        bool is_palindrome = true;
        for (int i = 0; i < i_tostr.size() / 2; i++)
        {
            if (i_tostr[i] != i_tostr[i_tostr.size() - 1 - i])
            {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
            
        cin >> input;
    }
}