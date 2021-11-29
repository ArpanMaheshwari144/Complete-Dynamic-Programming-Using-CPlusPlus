#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n)
{
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
    return t[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5;

    bool ans = subsetSum(arr, sum, n);

    if (ans)
    {
        cout << "Yes! Subset is exist.";
    }
    else
    {
        cout << "No! Subset is not exist.";
    }

    return 0;
}