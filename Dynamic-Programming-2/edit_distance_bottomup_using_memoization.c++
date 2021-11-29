/*Given two strings s1 and s2 and three operations(insert, remove and replace) that can performed on str1. Find minimum number of edits (operations) required to convert ‘s1’ into ‘s2’.*/
#include <bits/stdc++.h>
using namespace std;

/*Here i is changing to 0 to n-1 -> n and j is changing to 0 to m-1 -> m which means this is bottom-up approach so the parameter on which memoization is done is n and m so we use 2-D vector.*/
int editDistance(int i, int j, string s1, string s2, vector<vector<int>> &t)
{
    if (i == s1.size())
    {
        return s2.size() - j;
    }

    if (j == s2.size())
    {
        return s1.size() - i;
    }

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    // if both characters are same
    if (s1[i] == s2[j])
    {
        return t[i][j] = editDistance(i + 1, j + 1, s1, s2, t);
    }
    else
    {
        int left = 1 + editDistance(i, j + 1, s1, s2, t);      // insert
        int mid = 1 + editDistance(i + 1, j, s1, s2, t);       // remove
        int right = 1 + editDistance(i + 1, j + 1, s1, s2, t); // replace
        return t[i][j] = min(left, min(mid, right));
    }
}

int main()
{
    string s1 = "sunday";
    string s2 = "saturday";
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> t(n, vector<int>(m, -1));

    cout << editDistance(0, 0, s1, s2, t);

    return 0;
}