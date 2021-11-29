/*Given two strings S1 and S2, find the length of the longest common subsequence.*/
#include <bits/stdc++.h>
using namespace std;

/*Here i is changing to n-1 to 0 -> n and j is changing to m-1 to 0 -> m which means this is top-down approach so the parameter on which memoization is done is n and m so we use 2-D vector.*/
int lcs(int i, int j, string s1, string s2, vector<vector<int>> &t)
{
    // Base Case
    if (i < 0 || j < 0)
    {
        return 0;
    }

    // if the state has been visited previously
    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    if (s1[i] == s2[j])
    {
        return 1 + lcs(i - 1, j - 1, s1, s2, t);
    }
    else
    {
        int left = lcs(i - 1, j, s1, s2, t);
        int right = lcs(i, j - 1, s1, s2, t);
        return max(left, right);
    }
}

int main()
{
    string s1 = "ACD";
    string s2 = "CED";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> t(n, vector<int>(m, -1));

    cout << lcs(n - 1, m - 1, s1, s2, t);

    return 0;
}