#include <bits/stdc++.h>
using namespace std;

void printShortestCommonSupersequence(string X, string Y, int n, int m)
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
    int index = t[n][m];
    string s = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            s.push_back(X[i - 1]);
            i--;
            j--;
            index--;
        }
        else if (t[i - 1][j] > t[i][j - 1])
        {
            s.push_back(X[i - 1]);
            i--;
            index--;
        }
        else
        {
            s.push_back(Y[j - 1]);
            j--;
            index--;
        }
    }
    while (i > 0)
    {
        s.push_back(X[i - 1]);
        i--;
        index--;
    }
    while (j > 0)
    {
        s.push_back(Y[j - 1]);
        j--;
        index--;
    }
    reverse(s.begin(), s.end());
    cout << "Shortest Common Supersequence of " << X << " and " << Y << " is " << s;
}

int main()
{
    string X = "geek";
    string Y = "eke";

    int n = X.size();
    int m = Y.size();

    printShortestCommonSupersequence(X, Y, n, m);

    return 0;
}