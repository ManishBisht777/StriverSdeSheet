void rotate(vector<vector<int>> &matrix)
{
    reverse(matrix.begin(), matrix.end());

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// code studio vala
void rotateMatrix(vector<vector<int>> &mat, int rows, int columns)
{
    int rowDiv = rows / 2;
    int colDiv = columns / 2;
    int topLeft;
    for (int x = 0, y = 0; x < rowDiv && y < colDiv; x++, y++)
    {
        topLeft = mat[x][y];

        for (int row = x; row < rows - x - 1; row++)
            mat[row][y] = mat[row + 1][y];

        for (int col = y; col < columns - y - 1; col++)
            mat[rows - x - 1][col] = mat[rows - x - 1][col + 1];

        for (int row = rows - x - 1; row > x; row--)
            mat[row][columns - y - 1] = mat[row - 1][columns - y - 1];

        for (int col = columns - y - 1; col > y; col--)
            mat[x][col] = mat[x][col - 1];

        mat[x][y + 1] = topLeft;
    }
}