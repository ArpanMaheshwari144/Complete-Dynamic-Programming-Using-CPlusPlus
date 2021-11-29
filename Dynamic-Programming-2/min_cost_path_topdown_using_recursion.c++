/*Given a N x M matrix, find minimum cost path to reach top left from bottom right provided you can only move to up and left adjacent cells.*/
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int i, int j, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Base Case
    if (i == 0 && j == 0)
    {
        return mat[i][j];
    }

    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }

    int right = minCostPath(i, j - 1, mat); // moving left -> (i, j) -> (i, j-1)
    int left = minCostPath(i - 1, j, mat);  // moving up -> (i, j) -> (i-1, j)
    return (mat[i][j] + min(left, right));
}

int main()
{
    int n = 3, m = 3;

    vector<vector<int>> mat{
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3},
    };

    // OR

    // taking user input
    // vector<vector<int>> mat(n, vector<int>(m, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> mat[i][j];
    //     }
    // }

    cout << minCostPath(n - 1, m - 1, mat);

    return 0;
}