#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceRecursive(string X, string Y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (X[n - 1] == Y[m - 1])
    {
        return 1 + longestCommonSubsequenceRecursive(X, Y, n - 1, m - 1);
    }
    else
    {
        return max(longestCommonSubsequenceRecursive(X, Y, n, m - 1), longestCommonSubsequenceRecursive(X, Y, n - 1, m));
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int n = X.size();
    int m = Y.size();

    cout << "The length of longest common subsequence is " << longestCommonSubsequenceRecursive(X, Y, n, m);

    return 0;
}