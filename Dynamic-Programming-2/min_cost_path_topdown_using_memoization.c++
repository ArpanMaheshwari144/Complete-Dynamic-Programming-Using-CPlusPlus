/*Given a N x M matrix, find minimum cost path to reach top left from bottom right provided you can only move to up and left adjacent cells.*/
#include <bits/stdc++.h>
using namespace std;

/*Here i is changing to n-1 to 0 -> n and j is changing to m-1 to 0 -> m which means this is top-down approach so the parameter on which memoization is done is n and m so we use 2-D vector.*/
int minCostPath(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &t)
{
    int n = mat.size();
    int m = mat[0].size();

    if (i == 0 && j == 0)
    {
        return mat[i][j];
    }

    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    int right = minCostPath(i, j - 1, mat, t); // moving left -> (i, j) -> (i, j-1)
    int left = minCostPath(i - 1, j, mat, t);  // moving up -> (i, j) -> (i-1, j)
    return t[i][j] = (mat[i][j] + min(left, right));
}

int main()
{
    int n = 3, m = 3;

    vector<vector<int>> t(n, vector<int>(m, -1));

    vector<vector<int>> mat{
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3},
    };

    cout << minCostPath(n - 1, m - 1, mat, t);

    return 0;
}