/*Given N, find out the Nth Fibonacci Number.*/
#include <bits/stdc++.h>
using namespace std;

/*Here n is changing n to 0 which means n -> 0 ==> (n+1) which is top-down approach so the parameter on which memoization is done is n+1 so we use 1-D vector bcoz only one parameter is changing*/
int fibo(int n, vector<int> &t)
{
    // Base Case
    if (n <= 1)
    {
        return n;
    }

    // if previously the state has been visited or not
    if (t[n] != -1)
    {
        return t[n];
    }

    // memoize the answer
    t[n] = fibo(n - 1, t) + fibo(n - 2, t);

    return t[n];
}

int main()
{
    int n = 5;

    // 1-D vector of n+1 and initially all the values are -1
    vector<int> t(n + 1, -1);

    int ans = fibo(n, t);
    cout << ans;
    return 0;
}