vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int m1 = 0, m2 = 0, c1 = 0, c2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (m1 == arr[i])
            c1++;
        else if (m2 == arr[i])
            c2++;

        else if (c1 == 0)
        {
            m1 = arr[i];
            c1++;
        }
        else if (c2 == 0)
        {
            m2 = arr[i];
            c2++;
        }
        else
            c1--, c2--;
    }
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m1)
            c1++;
        else if (arr[i] == m2)
            c2++;
    }
    vector<int> ans;
    if (c1 > n / 3)
        ans.push_back(m1);
    if (c2 > n / 3)
        ans.push_back(m2);

    return ans;
}