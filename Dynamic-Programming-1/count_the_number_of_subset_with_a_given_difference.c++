#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]);
            }
        }
    }
    return t[n][sum];
}

int countNoOfSubsetWithGivenDiff(int arr[], int diff, int n)
{
    int sumOfArr = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfArr += arr[i];
    }

    int sum = (diff + sumOfArr) / 2;

    return countSubsetSum(arr, sum, n);
}

int main()
{
    /*int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int n = 4*/
    int arr[] = {1, 5, 3, 4, 2};
    int diff = 2;
    int n = 5;

    cout << countNoOfSubsetWithGivenDiff(arr, diff, n);
    return 0;
}
