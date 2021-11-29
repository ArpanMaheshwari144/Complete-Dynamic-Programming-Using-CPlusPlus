/*Given a sequence of N numbers, find the longest increasing subsequence which is contiguous and non-contiguous.*/
#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (v.back() < arr[i])
        {
            v.push_back(arr[i]);
        }
        else
        {
            // found immediate next or similar element
            int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[index] = arr[i];
        }
    }
    return v.size();
}

int main()
{
    int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, n);

    return 0;
}