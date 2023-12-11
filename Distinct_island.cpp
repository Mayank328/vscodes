void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &shape, int row0, int col0)
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    shape.push_back({row - row0, col - col0});
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i += 1)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, grid, vis, shape, row0, col0);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> distinct_island;
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < m; j += 1)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> shape;
                dfs(i, j, grid, vis, shape, i, j);
                distinct_island.insert(shape);
            }
        }
    }
    return distinct_island.size();
}