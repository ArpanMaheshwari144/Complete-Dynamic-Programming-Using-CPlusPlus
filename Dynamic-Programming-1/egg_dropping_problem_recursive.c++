#include <bits/stdc++.h>
using namespace std;

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

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        // max bcoz of worst case
        int tempAns = 1 + max(eggDrop(eggs - 1, k - 1), eggDrop(eggs, floors - k));

        // min bcoz question ask minimum number of attempts
        mn = min(mn, tempAns);
    }
    return mn;
}

int main()
{
    int eggs = 2;
    int floors = 36;

    cout << "Minimum number of trials in worst case with " << eggs << " eggs and " << floors << " floors is " << eggDrop(eggs, floors) << endl;

    return 0;
}