void getallpath(vector<vector<int>> &m,
                int n, int row, int col, vector<string> &ans, string cur)
{
    if (row >= n || col >= n || row < 0 || col < 0 ||
        m[row][col] == 0)
        return;

    if (row == n - 1 and col == n - 1)
    {
        ans.push_back(cur);
        return;
    }

    // now if its one we have 4 calls
    m[row][col] = 0;

    getallpath(m, n, row - 1, col, ans, cur + "U");
    getallpath(m, n, row, col + 1, ans, cur + "R");
    getallpath(m, n, row, col - 1, ans, cur + "L");
    getallpath(m, n, row + 1, col, ans, cur + "D");

    m[row][col] = 1;

    return;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    getallpath(m, n, 0, 0, ans, "");
    return ans;
}