/*Given an array with non negative numbers, divide the array into two parts such that the average of both the parts is equal. Print the both parts if they exists.*/
#include <bits/stdc++.h>
using namespace std;

/*Here index is changing to 0 to n-1 -> n, sum is changing to 0 to sum -> sum+1 and element is changing to 1 to n-1 -> n which means this is bottom-up approach so the parameter on which memoization is done is n, sum+1 and n so we use 3-D vector.*/
bool check(int index, int sum, int element, vector<int> &v, vector<int> &res, vector<vector<vector<bool>>> &t)
{
    // Base Case
    if (element == 0)
    {
        return (sum == 0);
    }

    // Base Case
    if (index >= v.size())
    {
        return false;
    }

    if (t[index][sum][element] == false)
    {
        return false;
    }

    if (v[index] <= sum)
    {
        res.push_back(v[index]);

        // for taking the element
        if (check(index + 1, sum - v[index], element - 1, v, res, t))
        {
            return t[index][sum][element] = true;
        }
        res.pop_back();
    }

    // for not taking the element
    if (check(index + 1, sum, element, v, res, t))
    {
        return t[index][sum][element] = true;
    }
    return t[index][sum][element] = false;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int n = v.size();

    int sum = 0;

    /*for-each loop to calculate the sum of the vector elements. (auto it) -> means this is a automatically iterator to traverse the vector.*/
    for (auto it : v)
    {
        sum += it;
    }

    vector<vector<vector<bool>>> t(n, vector<vector<bool>>(sum + 1, vector<bool>(n, true)));

    for (int i = 1; i <= n - 1; i++)
    {
        if ((sum * i) % n == 0)
        {
            int sum1 = i * sum;
            sum1 /= n;
            vector<int> res;

            if (check(0, sum1, i, v, res, t))
            {
                for (auto it : res)
                {
                    cout << it << " ";
                }
                return 0;
            }
        }
    }
    cout << -1;

    return 0;
}