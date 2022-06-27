vector<int> findSpans(vector<int> &prices)
{
    // Write your code here.
    stack<pair<int, int>> st;
    int n = prices.size();

    for (int i = 0; i < n; i++)
    {
        int cur = 1;
        if (!st.empty())
        {
            while (!st.empty() && prices[i] >= st.top().first)
            {
                cur += st.top().second;
                st.pop();
            }
        }

        st.push({prices[i], cur});
        prices[i] = cur;
    }

    return prices;
}