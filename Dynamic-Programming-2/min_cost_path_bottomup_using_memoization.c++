/*Given a N x M matrix, find minimum cost path to reach bottom right from top left provided you can only move to down and right adjacent cells.*/
#include <bits/stdc++.h>
using namespace std;

/*Here i is changing to 0 to n-1 -> n and j is changing to 0 to m-1 -> m which means this is bottom-up approach so the parameter on which memoization is done is n and m so we use 2-D vector.*/
int minCostPath(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &t)
{
    int n = mat.size();
    int m = mat[0].size();

    if (i == (n - 1) && j == (m - 1))
    {
        return mat[i][j];
    }

    if (i >= n || j >= m)
    {
        return INT_MAX;
    }

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    int right = minCostPath(i, j + 1, mat, t); // moving right
    int left = minCostPath(i + 1, j, mat, t);  // moving bottom
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

    cout << minCostPath(0, 0, mat, t);

    return 0;
}