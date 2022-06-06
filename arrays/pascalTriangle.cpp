vector<vector<int>> generate(int n)
{

    if (n == 1)
        return {{1}};
    vector<vector<int>> mat;
    mat.push_back({1});
    int size = 2;

    for (int i = 1; i < n; i++)
    {
        vector<int> ans(size, 0);
        ans[0] = 1;
        for (int j = 1; j < i; j++)
        {
            ans[j] = mat[i - 1][j - 1] + mat[i - 1][j];
        }
        ans[size - 1] = 1;

        size++;
        mat.push_back(ans);
    }

    return mat;
}