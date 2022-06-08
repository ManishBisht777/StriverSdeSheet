pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int xors = arr[0];
    for (int i = 1; i < n; i++)
    {
        xors = xors ^ arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        xors = xors ^ i;
    }

    int setbit = xors & ~(xors - 1);

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setbit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & setbit)
            x ^= i;
        else
            y ^= i;
    }
    int xcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            xcount++;
    }
    if (xcount == 0)
        return {x, y};

    return {y, x};
}