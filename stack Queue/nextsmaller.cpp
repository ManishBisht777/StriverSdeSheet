vector<int> Solution::prevSmaller(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        if (st.empty())
            arr[i] = -1;
        else
        {
            while (!st.empty() && st.top() >= curr)
                st.pop();

            if (st.empty())
                arr[i] = -1;
            else
                arr[i] = st.top();
        }

        st.push(curr);
    }

    return arr;
}