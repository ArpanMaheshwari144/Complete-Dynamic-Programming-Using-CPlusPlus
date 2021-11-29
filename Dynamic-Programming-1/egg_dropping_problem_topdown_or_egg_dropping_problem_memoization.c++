#include <bits/stdc++.h>
using namespace std;

int t[101][10001];

// int eggDrop(int eggs, int floors)
// {
//     if (floors == 0 || floors == 1)
//     {
//         return floors;
//     }
//     if (eggs == 1)
//     {
//         return floors;
//     }
//     if (t[eggs][floors] != -1)
//     {
//         return t[eggs][floors];
//     }

//     int mn = INT_MAX;
//     for (int k = 1; k <= floors; k++)
//     {
//         // max bcoz of worst case
//         // int tempAns = 1 + max(eggDrop(eggs - 1, k - 1), eggDrop(eggs, floors - k));

//         // OR

//         int low, high;
//         if (t[eggs - 1][k - 1] != -1)
//         {
//             low = t[eggs - 1][k - 1];
//         }
//         else
//         {
//             low = eggDrop(eggs - 1, k - 1);
//             t[eggs - 1][k - 1] = low;
//         }
//         if (t[eggs][floors - k] != -1)
//         {
//             high = t[eggs][floors - k];
//         }
//         else
//         {
//             high = eggDrop(eggs, floors - k);
//             t[eggs][floors - k] = high;
//         }
//         int tempAns = 1 + max(low, high);

//         // min bcoz question ask minimum number of attempts
//         mn = min(mn, tempAns);
//     }
//     return t[eggs][floors] = mn;
// }

//*****************************OR********************************************

int eggDrop(int eggs, int floors)
{
    if (floors == 0 || floors == 1)
    {
        return floors;
    }
    if (eggs == 1)
    {
        return floors;
    }
    if (t[eggs][floors] != -1)
    {
        return t[eggs][floors];
    }

    int mn = INT_MAX;
    int start = 1, end = floors;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int low, high;
        if (t[eggs - 1][mid - 1] != -1)
        {
            low = t[eggs - 1][mid - 1];
        }
        else
        {
            low = eggDrop(eggs - 1, mid - 1);
            t[eggs - 1][mid - 1] = low;
        }
        if (t[eggs][floors - mid] != -1)
        {
            high = t[eggs][floors - mid];
        }
        else
        {
            high = eggDrop(eggs, floors - mid);
            t[eggs][floors - mid] = high;
        }
        int tempAns = 1 + max(low, high);

        if (low < high)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mn = min(mn, tempAns);
    }
    return t[eggs][floors] = mn;
}

int main()
{
    int eggs = 2;
    int floors = 36;

    memset(t, -1, sizeof(t));

    cout << "Minimum number of trials in worst case with " << eggs << " eggs and " << floors << " floors is " << eggDrop(eggs, floors) << endl;

    return 0;
}