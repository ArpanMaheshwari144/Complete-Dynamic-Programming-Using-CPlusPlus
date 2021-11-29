/*Given an array with non negative numbers, divide the array into two parts such that the average of both the parts is equal. Print the both parts if they exists.*/
#include <bits/stdc++.h>
using namespace std;

bool check(int index, int sum, int element, vector<int> &v, vector<int> &res)
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

    if (v[index] <= sum)
    {
        res.push_back(v[index]);

        // for taking the element
        if (check(index + 1, sum - v[index], element - 1, v, res))
        {
            return true;
        }
        res.pop_back();
    }

    // for not taking the element
    if (check(index + 1, sum, element, v, res))
    {
        return true;
    }
    return false;
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

    for (int i = 1; i <= n - 1; i++)
    {
        if ((sum * i) % n == 0)
        {
            int sum1 = i * sum;
            sum1 /= n;
            vector<int> res;

            if (check(0, sum1, i, v, res))
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