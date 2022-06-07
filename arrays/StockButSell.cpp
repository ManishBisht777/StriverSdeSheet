int maxProfit(vector<int> &prices)
{

    int profit = 0;
    int ans = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        profit += prices[i] - prices[i - 1];
        ans = max(profit, ans);
        if (profit < 0)
            profit = 0;
    }

    return ans;
}