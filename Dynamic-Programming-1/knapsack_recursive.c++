#include <bits/stdc++.h>
using namespace std;

int knapsackRecursive(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapsackRecursive(wt, val, W, n - 1);
    }
    else
    {
        return max(val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n - 1), knapsackRecursive(wt, val, W, n - 1));
    }
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = 4;

    cout << knapsackRecursive(wt, val, W, n);

    return 0;
}