#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int v)
{
    sort(coins, coins + n);

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (v <= 0)
            break;
        v -= coins[i];
        ans++;
    }

    return ans;
}

int main()
{
    int coins[] = {25, 10, 5};
    int m = sizeof(coins) / sizeof(coins[0]);
    int v = 30;
    cout << "Minimum coins required is "
         << minCoins(coins, m, v);
    return 0;
}