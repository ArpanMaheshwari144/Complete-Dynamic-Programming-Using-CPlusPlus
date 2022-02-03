/* Problem Statement - Frog jump with K distance
There are N stones, numbered 1,2,…,N. For each i (1 ≤ i ≤ N), the height of Stone i is hi.
There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K.. Here, a cost of ∣hi−hj∣ is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.
 
Input: Input is given from Standard Input in the following format:
N K
h1 h2 … hN
​
Output: Print the minimum possible total cost incurred.

Sample Input 1 
5 3
10 30 40 50 20

Sample Output 1 
30
If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input 2 
3 1
10 20 10

Sample Output 2 
20
If we follow the path 1 → 2 → 3, the total cost incurred would be ∣10−20∣+∣20−10∣=20.
*/

#include <bits/stdc++.h>
using namespace std;

// DP - Tabulation
int main()
{
    int n, k;
    cout << "Enter the value of n & k: ";
    cin >> n >> k;

    vector<int> a(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                minSteps = min(minSteps, dp[i - j] + abs(a[i] - a[i - j]));
            }
        }
        dp[i] = minSteps;
    }
    cout << dp[n - 1] << endl;

    return 0;
}