#include <bits/stdc++.h>
using namespace std;

int countAllLongestCommonSubsequence(string X, string Y, int n, int m)
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
            if (X[i - 1] == Y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[n][m];
}

set<string> printAllLongestCommonSubsequence(string X, string Y, int n, int m)
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
            if (X[i - 1] == Y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }

    set<string> s;

    if (n == 0 || m == 0)
    {
        s.insert("");
        return s;
    }

    if (X[n - 1] == Y[m - 1])
    {
        set<string> tmp = printAllLongestCommonSubsequence(X, Y, n - 1, m - 1);

        for (string str : tmp)
        {
            s.insert(str + X[n - 1]);
        }
    }
    else
    {
        if (t[n - 1][m] >= t[n][m - 1])
        {
            s = printAllLongestCommonSubsequence(X, Y, n - 1, m);
        }
        if (t[n][m - 1] >= t[n - 1][m])
        {
            set<string> tmp = printAllLongestCommonSubsequence(X, Y, n, m - 1);
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}

int main()
{
    string X = "ABCBDAB";
    string Y = "BDCABA";

    int m = X.length();
    int n = Y.length();

    cout << "Count of all LCS length is " << countAllLongestCommonSubsequence(X, Y, m, n) << endl;

    set<string> s = printAllLongestCommonSubsequence(X, Y, m, n);

    for (string str : s)
    {
        cout << "LCS of " << X << " and " << Y << " is " << str << endl;
    }

    return 0;
}