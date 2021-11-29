/*Given N, find out the Nth Fibonacci Number.*/
#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    // Base Case
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return (fibo(n - 1) + fibo(n - 2));
    }
}

int main()
{
    int n = 5;
    cout << fibo(n);
    return 0;
}