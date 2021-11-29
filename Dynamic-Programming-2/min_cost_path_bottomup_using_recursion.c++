/*Given a N x M matrix, find minimum cost path to reach bottom right from top left provided you can only move to down and right adjacent cells.*/
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int i, int j, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Base Case
    if (i == (n - 1) && j == (m - 1))
    {
        return mat[i][j];
    }

    if (i >= n || j >= m)
    {
        return INT_MAX;
    }

    int right = minCostPath(i, j + 1, mat); // moving right -> (i, j) -> (i, j+1)
    int left = minCostPath(i + 1, j, mat);  // moving bottom -> (i, j) -> (i+1, j)
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

    cout << minCostPath(0, 0, mat);

    return 0;
}