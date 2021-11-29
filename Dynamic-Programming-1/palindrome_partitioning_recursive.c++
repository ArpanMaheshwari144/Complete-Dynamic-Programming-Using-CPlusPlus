#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s, int i, int j)
{
    if (i == j)
    {
        return true;
    }
    if (i > j)
    {
        return true;
    }

    // Using two pointer technique to check pallindrome
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromePartitioningRecursive(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (isPallindrome(s, i, j) == true)
    {
        return 0;
    }

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = 1 + palindromePartitioningRecursive(s, i, k) + palindromePartitioningRecursive(s, k + 1, j);

        if (tempAns < mn)
        {
            mn = tempAns;
        }
    }
    return mn;
}

int main()
{
    string s = "abbac";
    int n = s.size();
    int i = 0;
    int j = n - 1;

    cout << "The minimum number of partition to make string " << s << " palindrome is " << palindromePartitioningRecursive(s, i, j);

    return 0;
}