#include <bits/stdc++.h>
using namespace std;

void printLongestRepeatingSubsequence(string X, string Y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (X[i - 1] == Y[j - 1] && i != j)
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    string s = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (t[i][j] == t[i - 1][j - 1] + 1)
        {
            s = s + X[i - 1];
            i--;
            j--;
        }
        else if (t[i][j] == t[i - 1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << "The longest repeating subsequence of " << X << " is " << s;

    // OR

    // string s = "";
    // int i = n, j = m;

    // while (i > 0 && j > 0)
    // {
    //     if (X[i - 1] == Y[j - 1] && i != j)
    //     {
    //         s = s + (X[i - 1]);
    //         i--;
    //         j--;
    //     }
    //     else if (t[i][j] == t[i - 1][j])
    //     {
    //         i--;
    //     }
    //     else
    //     {
    //         j--;
    //     }
    // }
    // reverse(s.begin(), s.end());
    // cout << "The longest repeating subsequence of " << X << " is " << s;
}

int main()
{
    string X = "AABEBCDD";
    string Y = X;

    int n = X.size();
    int m = Y.size();

    printLongestRepeatingSubsequence(X, Y, n, m);

    return 0;
}