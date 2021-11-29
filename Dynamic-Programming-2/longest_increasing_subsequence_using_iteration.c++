/*Given a sequence of N numbers, find the longest increasing subsequence which is contiguous and non-contiguous.*/
#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
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
    return *max_element(lis, lis + n);
}

int main()
{
    int arr[] = {50, 3, 10, 7, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << lis(arr, n);

    return 0;
}