/* Count of subsets with sum equal to target -> Given an array arr[] of length N and an integer target, the task is to find the number of subsets with a sum equal to target.

Examples:
Input: arr[] = {1, 2, 3, 3}, target = 6
Output: 3
All the possible subsets are {1, 2, 3}, {1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, target = 1
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
/*
int findWays(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (index == 0)
    {
        return arr[0] == sum;
    }

    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    int notTake = findWays(index - 1, sum, arr, dp);
    int take = 0;
    if (arr[index] <= sum)
    {
        take = findWays(index - 1, sum - arr[index], arr, dp);
    }
    return dp[index][sum] = take + notTake;
}
*/

int main()
{
    // Recursion + Memoization
    /*
    vector<int> arr = {1, 2, 3, 3};
    int n = arr.size();
    int target = 6;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int ans = findWays(n - 1, target, arr, dp);
    cout << "Total number is: " << ans;
    */

    // Tabulation
    /*
    vector<int> arr = {1, 2, 3, 3};
    int n = arr.size();
    int target = 6;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notTake = dp[index - 1][sum];
            int take = 0;
            if (arr[index] <= sum)
            {
                take = dp[index - 1][sum - arr[index]];
            }
            dp[index][sum] = take + notTake;
        }
    }
    cout << "Total number is: " << dp[n - 1][target];
    */

    // Space Optimization
    vector<int> arr = {1, 2, 3, 3};
    int n = arr.size();
    int target = 6;

    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    prev[0] = curr[0] = 1;

    if (arr[0] <= target)
    {
        prev[arr[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (arr[index] <= sum)
            {
                take = prev[sum - arr[index]];
            }
            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    cout << "Total number is: " << prev[target];

    return 0;
}