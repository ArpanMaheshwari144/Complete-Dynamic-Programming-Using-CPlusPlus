/* Counts Subsets with Sum K or Number of Subsets -> You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.

Note: Two ways are considered different if sets of indexes of elements chosen by these ways are different.

Input Format : The first line of the input contains an integer, 'T’, denoting the number of test cases.
The first line of each test case will contain two space-separated integers ‘N’ and “tar”, denoting the size of the array and the target sum.
The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.

Constraints:
1 <= T <= 10
1 <= N <= 100
0 <= nums[i] <= 1000
1 <= tar <= 1000

Sample Input 1 :
1
3 1
0 0 1
Sample Output 1 :
4
Explanation: N = 3 and tar = 1 and array elements are [0, 0, 1] then the number of possible ways are:
{0, 1}, {0, 1}, {1}, {0, 0, 1}
Hence the output will be 4.

Sample Input 2 :
2
3 4
12 1 3
2 41
2 34
Sample Output 2 :
1
0
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
/*
int solve(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (sum == 0 && arr[0] == 0)
        {
            return 2;
        }
        if (sum == 0 || sum == arr[0])
        {
            return 1;
        }
        return 0;
    }

    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    int notTake = solve(index - 1, sum, arr, dp);
    int take = 0;
    if (arr[index] <= sum)
    {
        take = solve(index - 1, sum - arr[index], arr, dp);
    }
    return dp[index][sum] = take + notTake;
}
*/

int main()
{
    // Recursion + Memoization
    /*
    vector<int> num = {0, 0, 1};
    int tar = 1;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    cout << "Number of subsets are: " << solve(n - 1, tar, num, dp);
    */

    // Tabulation
    /*
    vector<int> num = {0, 0, 1};
    int tar = 1;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }

    if (num[0] != 0 && num[0] <= tar)
    {
        dp[0][num[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[index - 1][sum];
            int take = 0;
            if (num[index] <= sum)
            {
                take = dp[index - 1][sum - num[index]];
            }
            dp[index][sum] = take + notTake;
        }
    }
    cout << "Number of subsets are: " << dp[n - 1][tar];
    */

    // SpaceOptimization
    vector<int> num = {0, 0, 1};
    int tar = 1;
    int n = num.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

    if (num[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;
    }

    if (num[0] != 0 && num[0] <= tar)
    {
        prev[num[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[index] <= sum)
            {
                take = prev[sum - num[index]];
            }
            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    cout << "Number of subsets are: " << prev[tar];

    return 0;
}