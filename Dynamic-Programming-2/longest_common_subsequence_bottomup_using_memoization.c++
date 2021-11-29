/*if pointers move 0 to n-1 its bottom-up approach and if pointers move n-1 to 0 its top-down approach*/
/*Given two strings S1 and S2, find the length of the longest common subsequence.*/
#include <bits/stdc++.h>
using namespace std;

/*Here i is changing to 0 to n-1 -> n and j is changing to 0 to m-1 -> m which means this is bottom-up approach so the parameter on which memoization is done is n and m so we use 2-D vector.*/
int lcs(int i, int j, string s1, string s2, vector<vector<int>> &t)
{
    // Base Case
    if (i >= s1.size() || j >= s2.size())
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
        return 1 + lcs(i + 1, j + 1, s1, s2, t);
    }
    else
    {
        int left = lcs(i + 1, j, s1, s2, t);
        int right = lcs(i, j + 1, s1, s2, t);
        return t[i][j] = max(left, right);
    }
}

int main()
{
    string s1 = "ACD";
    string s2 = "CED";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> t(n, vector<int>(m, -1));

    cout << lcs(0, 0, s1, s2, t);

    return 0;
}