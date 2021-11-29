/*Given two strings s1 and s2 and three operations(insert, remove and replace) that can performed on str1. Find minimum number of edits (operations) required to convert ‘s1’ into ‘s2’.*/
#include <bits/stdc++.h>
using namespace std;

int editDistance(int i, int j, string s1, string s2)
{
    if (i < 0)
    {
        return j + 1;
    }

    if (j < 0)
    {
        return i + 1;
    }

    // if both characters are same
    if (s1[i] == s2[j])
    {
        return editDistance(i - 1, j - 1, s1, s2);
    }
    else
    {
        int left = 1 + editDistance(i, j - 1, s1, s2);      // insert
        int mid = 1 + editDistance(i - 1, j, s1, s2);       // remove
        int right = 1 + editDistance(i - 1, j - 1, s1, s2); // replace
        return min(left, min(mid, right));
    }
}

int main()
{
    string s1 = "sunday";
    string s2 = "saturday";
    int n = s1.size();
    int m = s2.size();

    cout << editDistance(n - 1, m - 1, s1, s2);

    return 0;
}