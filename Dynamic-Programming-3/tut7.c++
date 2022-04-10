#include <bits/stdc++.h>
using namespace std;

void printLongestCommonSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev; // storing the prev index into the hash array
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());

    cout << "The length of longest increasing subseqence is: " << maxi << endl;
    cout << "Longest increasing subsequence is: ";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 7, 8, 4, 5, 6, -1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printLongestCommonSubsequence(arr, n);

    return 0;
}