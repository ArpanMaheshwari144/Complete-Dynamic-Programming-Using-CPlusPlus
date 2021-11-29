/*Given a bag which can only take certain weight W. Also given are list of items with their weights and values. How do you fill this bag to maximize value of items in the bag such that the weight constraint is maintained.*/
#include <bits/stdc++.h>
using namespace std;

/*Here index is changing to 0 to n-1 -> n and W is changing to 0 to W -> W+1 which means this is bottom-up approach so the parameter on which memoization is done is n and W+1 so we use 2-D vector.*/
int knapsack(int index, int W, int value[], int weight[], int n, vector<vector<int>> &t)
{
    //index out of bound
    if (index >= n)
    {
        return 0;
    }

    // bag is full
    if (W == 0)
    {
        return 0;
    }

    if (t[index][W] != -1)
    {
        return t[index][W];
    }

    if (weight[index] <= W)
    {
        int left = value[index] + knapsack(index + 1, W - weight[index], value, weight, n, t);
        int right = knapsack(index + 1, W, value, weight, n, t);
        return t[index][W] = max(left, right);
    }
    else
    {
        return t[index][W] = knapsack(index + 1, W, value, weight, n, t);
    }
}

int main()
{
    int weight[] = {25, 25, 30};
    int value[] = {100, 100, 180};
    int n = sizeof(weight) / sizeof(weight[0]);
    int W = 50;

    vector<vector<int>> t(n, vector<int>(W + 1, -1));

    cout << knapsack(0, W, value, weight, n, t);

    return 0;
}