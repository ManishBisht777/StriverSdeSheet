int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> s;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }

    int c = s.top();

    for (int i = 0; i < n; i++)
    {
        if (i != c)
        {
            if (M[i][c] == 0 || M[c][i] == 1)
                return -1;
        }
    }
    return c;
}