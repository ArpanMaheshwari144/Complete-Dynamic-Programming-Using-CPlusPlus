#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsackRecursive(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return unboundedKnapsackRecursive(wt, val, W, n - 1);
    }
    else
    {
        return max(val[n - 1] + unboundedKnapsackRecursive(wt, val, W - wt[n - 1], n), unboundedKnapsackRecursive(wt, val, W, n - 1));
    }
}

int main()
{
    int wt[] = {1, 50};
    int val[] = {1, 30};
    int W = 100;
    int n = 2;

    cout << unboundedKnapsackRecursive(wt, val, W, n);

    return 0;
}