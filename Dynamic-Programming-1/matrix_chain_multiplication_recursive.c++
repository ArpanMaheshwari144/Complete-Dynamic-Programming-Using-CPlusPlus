#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    int min = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

        if (tempAns < min)
        {
            min = tempAns;
        }
    }
    return min;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 1;
    int j = n - 1;

    cout << solve(arr, i, j);

    return 0;
}