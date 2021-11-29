#include <bits/stdc++.h>
using namespace std;

int minNumberOfCoinChange(int coin[], int sum, int n)
{
    int t[n + 1][sum + 1];

    for (int i = 1; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j < sum + 1; j++)
    {
        t[0][j] = INT_MAX - 1;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        if (j % coin[0] == 0)
        {
            t[1][j] = j / coin[0];
        }
        else
        {
            t[1][j] = INT_MAX - 1;
        }
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = min((1 + t[i][j - coin[i - 1]]), t[i - 1][j]);
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int coin[] = {1, 2, 5};
    int sum = 11;
    int n = 3;

    int minCoin = minNumberOfCoinChange(coin, sum, n);
    if (minCoin == INT_MAX - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << "The minimum number of coins for given sum is: " << minCoin;
    }

    return 0;
}