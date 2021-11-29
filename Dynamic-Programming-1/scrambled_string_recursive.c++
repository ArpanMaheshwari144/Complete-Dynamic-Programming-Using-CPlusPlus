#include <bits/stdc++.h>
using namespace std;

bool isScramble(string X, string Y)
{
    int n = X.length();
    int m = Y.length();
    if (n != m)
    {
        return false;
    }
    if (n == 0 && m == 0)
    {
        return true;
    }
    if (X == Y)
    {
        return true;
    }

    /*Check for the condition of anagram -> it indicates that the strings contain different characters
    and can’t be a scrambled form of each other.*/
    // this condition is applying for the optimisation of code. If large strings are in the input
    string copy_X = X, copy_Y = Y;

    sort(copy_X.begin(), copy_X.end());
    sort(copy_Y.begin(), copy_Y.end());

    if (copy_X != copy_Y)
    {
        return false;
    }

    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        // Swap Condition
        if (isScramble(X.substr(0, i), Y.substr(n - i, i)) && isScramble(X.substr(i, n - i), Y.substr(0, n - i)))
        {
            flag = true;
            break;
        }

        // No-Swap Condition
        if (isScramble(X.substr(0, i), Y.substr(0, i)) && isScramble(X.substr(i, n - i), Y.substr(i, n - i)))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    /*string X = "coder";
    string Y = "ocder";*/

    string X = "abcdefghijklmn";
    string Y = "efghijklmncadb";

    if (isScramble(X, Y))
    {
        cout << "True! Both String are Scrambled" << endl;
    }
    else
    {
        cout << "False! Both String are not Scrambled" << endl;
    }

    return 0;
}