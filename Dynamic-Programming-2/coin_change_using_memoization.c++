/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = {S1, S2,.., Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.*/
#include <bits/stdc++.h>
using namespace std;

/*Here index is changing to 0 to n-1 -> n and sum is changing to 0 to sum -> sum+1 which means this is bottom-up approach so the parameter on which memoization is done is index and sum+1 so we use 2-D vector.*/
int coinChange(int index, int sum, int arr[], int n, vector<vector<int>> &t)
{
    if (sum == 0)
    {
        return 1;
    }

    if (index >= n || sum < 0)
    {
        return 0;
    }

    if (t[index][sum] != -1)
    {
        return t[index][sum];
    }

    int left = coinChange(index, sum - arr[index], arr, n, t);
    int right = coinChange(index + 1, sum, arr, n, t);
    return t[index][sum] = left + right;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;

    vector<vector<int>> t(n, vector<int>(sum + 1, -1));

    cout << coinChange(0, sum, arr, n, t);

    return 0;
}