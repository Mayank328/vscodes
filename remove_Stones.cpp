#include <bits/stdc++.h>
using namespace std;
class dsu
{
    vector<int> rank, parent, size;

public:
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for (auto it : stones)
        {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        dsu ds(maxrow + maxcol + 1);
        unordered_map<int, int> mp;
        for (auto it : stones)
        {
            int rownode = it[0];
            int colnode = it[1] + maxrow + 1;
            ds.us(rownode, colnode);
            mp[rownode] = 1;
            mp[colnode] = 1;
        }
        int cnt = 0;
        for (auto it : mp)
        {
            if (ds.fup(it.first) == it.first)
            {
                cnt += 1;
            }
        }
        return n - cnt;
    }
};