// Dimensions of matrix/Key of map always depends on the number of variables that are change in call of recursive function

// By Using 3d matrix

// #include <bits/stdc++.h>
// using namespace std;

// int t[1001][1001][2];

// int countBooleanParenthesisTopDown(string X, int i, int j, int isTrue)
// {
//     //Base Condition
//     if (i > j)
//     {
//         return 0;
//     }
//     if (i == j)
//     {
//         if (isTrue)
//         {
//             if (X[i] == 'T')
//             {
//                 return 1;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         else
//         {
//             if (X[i] == 'F')
//             {
//                 return 1;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//     }

//     if (t[i][j][isTrue] != -1)
//     {
//         return t[i][j][isTrue];
//     }

//     int ans = 0;
//     for (int k = i + 1; k <= j - 1; k = k + 2)
//     {
//         int leftFalse, leftTrue, rightFalse, rightTrue;
//         if (t[i][k - 1][true] == -1)
//         {
//             leftTrue = countBooleanParenthesisTopDown(X, i, k - 1, true);
//         }
//         else
//         {
//             leftTrue = t[i][k - 1][true];
//         }

//         if (t[k + 1][j][true] == -1)
//         {
//             rightTrue = countBooleanParenthesisTopDown(X, k + 1, j, true);
//         }
//         else
//         {
//             rightTrue = t[k + 1][j][true];
//         }

//         if (t[i][k - 1][false] == -1)
//         {
//             leftFalse = countBooleanParenthesisTopDown(X, i, k - 1, false);
//         }
//         else
//         {
//             leftFalse = t[i][k - 1][false];
//         }

//         if (t[k + 1][j][false] == -1)
//         {
//             rightFalse = countBooleanParenthesisTopDown(X, k + 1, j, false);
//         }
//         else
//         {
//             rightFalse = t[k + 1][j][false];
//         }

//         if (X[k] == '&')
//         {
//             if (isTrue)
//             {
//                 ans = ans + (leftTrue * rightTrue);
//             }
//             else
//             {
//                 ans = ans + (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
//             }
//         }
//         else if (X[k] == '|')
//         {
//             if (isTrue)
//             {
//                 ans = ans + (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
//             }
//             else
//             {
//                 ans = ans + (leftFalse * rightFalse);
//             }
//         }
//         else if (X[k] == '^')
//         {
//             if (isTrue)
//             {
//                 ans = ans + (leftTrue * rightFalse) + (leftFalse * rightTrue);
//             }
//             else
//             {
//                 ans = ans + (leftTrue * rightTrue) + (leftFalse * rightFalse);
//             }
//         }
//         t[i][j][isTrue] = ans;
//     }
//     return t[i][j][isTrue];
// }
// int main()
// {
//     string X = "T|T&F^T";
//     int n = X.size();
//     int i = 0;
//     int j = n - 1;

//     memset(t, -1, sizeof(t));

//     cout << "The given expression is " << X << ", it evaluates true in " << countBooleanParenthesisTopDown(X, i, j, true) << " ways";

//     return 0;
// }

// ******************************OR********************************************

// By Using unordered map

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int countBooleanParenthesisTopDown(string X, int i, int j, int isTrue)
{
    //Base Condition
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

    string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int leftTrue = countBooleanParenthesisTopDown(X, i, k - 1, true);
        int leftFalse = countBooleanParenthesisTopDown(X, i, k - 1, false);
        int rightTrue = countBooleanParenthesisTopDown(X, k + 1, j, true);
        int rightFalse = countBooleanParenthesisTopDown(X, k + 1, j, false);

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
    mp[temp] = ans;
    return mp[temp];
}

int main()
{
    string X = "T|T&F^T";
    int n = X.size();
    int i = 0;
    int j = n - 1;

    mp.clear();

    cout << "The given expression is " << X << ", it evaluates true in " << countBooleanParenthesisTopDown(X, i, j, true) << " ways";

    return 0;
}