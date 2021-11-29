#include <bits/stdc++.h>
using namespace std;

int t[102][1002];

int unboundedKnapsackMemoization(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    if (wt[n - 1] > W)
    {
        return t[n][W] = unboundedKnapsackMemoization(wt, val, W, n - 1);
    }
    else
    {
        return t[n][W] = max(val[n - 1] + unboundedKnapsackMemoization(wt, val, W - wt[n - 1], n), unboundedKnapsackMemoization(wt, val, W, n - 1));
    }
}

int main()
{
    int wt[] = {1, 50};
    int val[] = {1, 30};
    int W = 100;
    int n = 2;

    memset(t, -1, sizeof(t));

    cout << unboundedKnapsackMemoization(wt, val, W, n);

    return 0;
}