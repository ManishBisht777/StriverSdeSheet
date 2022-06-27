int orangesRotting(vector<vector<int>> &grid)
{

    if (grid.empty())
        return 0;

    queue<pair<int, int>> q;

    int n = grid.size();
    int m = grid[0].size();

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
                total++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int days = 0;
    int cnt = 0;

    while (!q.empty())
    {
        int k = q.size();
        cnt += k;

        while (k--)
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
                    continue;

                grid[nx][ny] = 2;

                q.push({nx, ny});
            }
        }

        if (!q.empty())
            days++;
    }

    return total == cnt ? days : -1;
}