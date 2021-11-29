/*Given some matrices, in what order you would multiply them to minimize cost of multiplication.*/
#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int i, int j, int arr[])
{
    // Base Case
    if (i == j)
    {
        return 0;
    }

    int min = INT_MAX;

    // this loop runs from i to j-1;
    for (int k = i; k < j; k++)
    {
        int count = matrixChainMultiplication(i, k, arr) + matrixChainMultiplication(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];

        if (count < min)
        {
            min = count;
        }
    }
    return min;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numberOfMatrices = n - 1;

    cout << matrixChainMultiplication(1, numberOfMatrices, arr);

    return 0;
}