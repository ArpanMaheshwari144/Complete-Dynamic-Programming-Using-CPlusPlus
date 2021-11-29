/*Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.*/

#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(int arr[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
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
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
        }
    }

    int diff = INT_MAX;

    for (int j = sum / 2; j >= 0; j--)
    {
        if (t[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = 6;
    cout << "The minimum difference between two sets is " << minSubsetSumDiff(arr, n);
    return 0;
}
