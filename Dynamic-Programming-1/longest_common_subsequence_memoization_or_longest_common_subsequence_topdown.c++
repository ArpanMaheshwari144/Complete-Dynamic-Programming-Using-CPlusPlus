#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

// lcs -> Longest Common Subsequence
int lcsMemoizationOrTopDown(string X, string Y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (t[n][m] != -1)
    {
        return t[n][m];
    }
    if (X[n - 1] == Y[m - 1])
    {
        return t[n][m] = 1 + lcsMemoizationOrTopDown(X, Y, n - 1, m - 1);
    }
    else
    {
        return t[n][m] = max(lcsMemoizationOrTopDown(X, Y, n, m - 1), lcsMemoizationOrTopDown(X, Y, n - 1, m));
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int n = X.size();
    int m = Y.size();

    memset(t, -1, sizeof(t));

    cout << "The length of longest common subsequence is " << lcsMemoizationOrTopDown(X, Y, n, m);

    return 0;
}