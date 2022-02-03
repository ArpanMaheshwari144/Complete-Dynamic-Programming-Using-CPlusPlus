// Fibonacci number using Dynamic Programming approach(Space Optimization)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur_i;
    }
    cout << n << "th fibonacci number is: " << prev1;

    return 0;
}