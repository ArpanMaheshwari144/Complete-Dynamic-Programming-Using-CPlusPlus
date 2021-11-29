#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string X, string Y, int n, int m)
{
    int t[n + 1][m + 1];
    int result = 0;
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
                result = max(result, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    string X = "zxabcdezy";
    string Y = "yzabcdezx";

    int n = X.size();
    int m = Y.size();

    cout << "The length of longest common substring is " << longestCommonSubstring(X, Y, n, m);

    return 0;
}