/*Given some matrices, in what order you would multiply them to minimize cost of multiplication.*/
#include <bits/stdc++.h>
using namespace std;

/*Here i is changing to 1 to n -> n and j is changing to 1 to n -> n which means this is bottom-up approach so the parameter on which memoization is done is n and n so we use 2 - D vector.*/
int matrixChainMultiplication(int i, int j, int arr[], vector<vector<int>> t)
{
    // Base Case
    if (i == j)
    {
        return 0;
    }

    int min = INT_MAX;

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    // this loop runs from i to j-1;
    for (int k = i; k < j; k++)
    {
        int count = matrixChainMultiplication(i, k, arr, t) + matrixChainMultiplication(k + 1, j, arr, t) + arr[i - 1] * arr[k] * arr[j];

        if (count < min)
        {
            min = count;
        }
    }
    return t[i][j] = min;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numberOfMatrices = n - 1;

    vector<vector<int>> t(n, vector<int>(n, -1));

    cout << matrixChainMultiplication(1, numberOfMatrices, arr, t);

    return 0;
}