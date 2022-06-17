double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    vector<pair<double, int>> val(n);

    for (int i = 0; i < n; i++)
    {
        val[i].first = (double)arr[i].value / arr[i].weight;
        val[i].second = arr[i].weight;
    }

    sort(val.begin(), val.end());

    double ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (W == 0)
            break;
        if (val[i].second <= W)
        {
            ans += (double)val[i].second * val[i].first;
            W -= val[i].second;
        }
        else
        {
            ans += (double)W * val[i].first;
            W = 0;
        }
    }

    return ans;
}