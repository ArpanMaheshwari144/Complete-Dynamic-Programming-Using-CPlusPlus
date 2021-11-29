/*Given a bag which can only take certain weight W. Also given are list of items with their weights and values. How do you fill this bag to maximize value of items in the bag such that the weight constraint is maintained.*/
#include <bits/stdc++.h>
using namespace std;

int knapsack(int index, int W, int value[], int weight[], int n)
{
    // index out of bound
    if (index >= n)
    {
        return 0;
    }

    // bag is full
    if (W == 0)
    {
        return 0;
    }

    // if item is taken
    if (weight[index] <= W)
    {
        int left = value[index] + knapsack(index + 1, W - weight[index], value, weight, n);
        int right = knapsack(index + 1, W, value, weight, n);
        return max(left, right);
    }
    else
    {
        return knapsack(index + 1, W, value, weight, n);
    }
}

int main()
{
    int weight[] = {25, 25, 30};
    int value[] = {100, 100, 180};
    int n = sizeof(weight) / sizeof(weight[0]);
    int W = 50;

    cout << knapsack(0, W, value, weight, n);

    return 0;
}