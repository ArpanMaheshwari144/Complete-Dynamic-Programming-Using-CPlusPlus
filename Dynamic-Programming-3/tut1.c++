/*
Recursion -> top-down -> n-1 to 0
Tabulation -> bottom-up -> 0 to n-1

Note: If recursion is top-down then Tabulation should be bottom-up approach OR If recursion is bottom-up then Tabulation should be top-down approach
*/
// Fibonacci number using Dynamic Programming approach(Memoization)

#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << n << "th fibonacci number is: " << fib(n, dp);

    return 0;
}