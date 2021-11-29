/*Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.*/
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

int targetSum(int arr[], int sum1, int n)
{
    int sumOfArr = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfArr += arr[i];
    }

    int sum = (sum1 + sumOfArr) / 2;

    return countSubsetSum(arr, sum, n);
}

int main()
{
    /*int arr[] = {1, 1, 2, 3};
    int sum = 1;*/
    /*int arr[] = {1, 5, 3, 4, 2};
    int sum = 2;
    int n = 5;*/
    int arr[] = {1, 1, 1, 1, 1};
    int sum = 3;
    int n = 5;

    cout << targetSum(arr, sum, n);

    return 0;
}