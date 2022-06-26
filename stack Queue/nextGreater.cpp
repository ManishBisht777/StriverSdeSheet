vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    stack<long long> st;

    for (int i = n - 1; i >= 0; i--)
    {
        long long curr = arr[i];

        if (st.empty())
            arr[i] = -1;
        else
        {
            while (!st.empty() && st.top() <= curr)
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