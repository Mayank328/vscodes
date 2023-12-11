class dsu
{
public:
    vector<int> rank, parent, size;
    dsu(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i += 1)
        {
            parent[i] = i;
        }
    }
    int get_size(int n)
    {
        return size[n];
    }
    int get_rank(int n)
    {
        return rank[n];
    }
    int fup(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = fup(parent[node]);
    }
    void ur(int u, int v)
    {
        int ulp_u = fup(u);
        int ulp_v = fup(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        else if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void us(int u, int v)
    {
        int ulp_u = fup(u);
        int ulp_v = fup(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if (size[ulp_v] < size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    bool isValid(int nrow, int ncol, int n)
    {
        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n);
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        dsu ds(n * n);
        for (int i = 0; i < n; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (grid[i][j] == 0)
                    continue;
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                for (int k = 0; k < 4; k += 1)
                {
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    if (isValid(nrow, ncol, n))
                    {
                        if (grid[nrow][ncol] == 1)
                        {
                            int node = i * n + j;
                            int adjnode = nrow * n + ncol;
                            if (ds.fup(node) != ds.fup(adjnode))
                            {
                                ds.us(node, adjnode);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (grid[i][j] == 1)
                    continue;
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                set<int> parent_set;
                for (int k = 0; k < 4; k += 1)
                {
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    if (isValid(nrow, ncol, n))
                    {
                        if (grid[nrow][ncol] == 1)
                        {
                            int adjnode = nrow * n + ncol;
                            parent_set.insert(ds.fup(adjnode));
                        }
                    }
                }
                int temp = 0;
                for (auto it : parent_set)
                {
                    temp += ds.size[it];
                }
                ans = max(ans, temp + 1);
            }
        }
        for (int i = 0; i < n * n; i += 1)
        {
            ans = max(ans, ds.size[ds.fup(i)]);
        }
        return ans;
    }
};