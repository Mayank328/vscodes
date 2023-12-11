//uses dsu to find the min spanning tree of a graph 
//first the edges matrix have to be sorted according to weights of the edges 
//sorting is necessary so that while iterating the edges list 
//we will be only taking the least edge weights of the edges and finding if the two nodes
//have ultimate parent same or not if not same then include in the min_spanning_sum
//then join the edges by rank or size 
//if same then continue cause that edges is already found with the least edges weight 
//and dont have to inlcuder that in our spanning tree/////////
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
    int findUparent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUparent(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
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
    void UnionBySize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
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
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        dsu ds(V);
        int min_sum = 0;
        for (int i = 0; i < V; i += 1)
        {
            for (auto it : adj[i])
            {
                int adjcent_node = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjcent_node}});
            }
        }
        sort(edges.begin(), edges.end());
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUparent(u) != ds.findUparent(v))
            {
                min_sum += wt;
                ds.UnionByRank(u, v);
            }
        }
        return min_sum;
    }
};