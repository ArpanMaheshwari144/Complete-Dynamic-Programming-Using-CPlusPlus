/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.*/
#include <bits/stdc++.h>
using namespace std;

int coinChange(int index, int sum, int arr[], int n)
{
    // Base Case
    if (sum == 0)
    {
        return 1;
    }

    // Base Case
    if (index >= n || sum < 0)
    {
        return 0;
    }

    int left = coinChange(index, sum - arr[index], arr, n);
    int right = coinChange(index + 1, sum, arr, n);
    return left + right;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;

    cout << coinChange(0, sum, arr, n);

    return 0;
}