/*Given a sequence of N numbers, print the longest increasing subsequence.*/
#include <bits/stdc++.h>
using namespace std;

void lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int index = 0;
    int mx = lis[0];

    for (int i = n - 1; i >= 0; i--)
    {
        if (lis[i] > mx)
        {
            mx = lis[i];
            index = i;
        }
    }

    vector<int> v;
    v.push_back(arr[index]);
    for (int i = index - 1; i >= 0; i--)
    {
        if (lis[i] + 1 == lis[index] && arr[i] < arr[index])
        {
            index = i;
            v.push_back(arr[index]);
        }
    }
    reverse(v.begin(), v.end());

    for (auto itr : v)
    {
        cout << itr << " ";
    }
}

int main()
{
    int arr[] = {50, 3, 10, 7, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    lis(arr, n);

    return 0;
}