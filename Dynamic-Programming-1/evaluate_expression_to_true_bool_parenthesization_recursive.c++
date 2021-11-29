#include <bits/stdc++.h>
using namespace std;

int countBooleanParenthesisRecursive(string X, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            if (X[i] == 'T')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (X[i] == 'F')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int leftTrue = countBooleanParenthesisRecursive(X, i, k - 1, true);
        int leftFalse = countBooleanParenthesisRecursive(X, i, k - 1, false);
        int rightTrue = countBooleanParenthesisRecursive(X, k + 1, j, true);
        int rightFalse = countBooleanParenthesisRecursive(X, k + 1, j, false);

        if (X[k] == '&')
        {
            if (isTrue)
            {
                ans = ans + (leftTrue * rightTrue);
            }
            else
            {
                ans = ans + (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
            }
        }
        else if (X[k] == '|')
        {
            if (isTrue)
            {
                ans = ans + (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else
            {
                ans = ans + (leftFalse * rightFalse);
            }
        }
        else if (X[k] == '^')
        {
            if (isTrue)
            {
                ans = ans + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else
            {
                ans = ans + (leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }
    }
    return ans;
}

int main()
{
    string X = "T|T&F^T";
    int n = X.size();
    int i = 0;
    int j = n - 1;

    cout << "The given expression is " << X << ", it evaluates true in " << countBooleanParenthesisRecursive(X, i, j, true) << " ways";

    return 0;
}