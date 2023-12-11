//kosaraju algorithm is used to find the strongly connected components.
//SCC are those components from which we can trverse the whole component by taking any  two nodes.
//single node from which we cannot travel to any other node also come under scc;
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    void dfsT(int node, vector<int> &vis, vector<int> adjR[])
    {
        vis[node] = 1;
        for (auto it : adjR[node])
        {
            if (!vis[it])
            {
                dfsT(it, vis, adjR);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i += 1)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> adjR[V];
        for (int i = 0; i < V; i += 1)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjR[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfsT(node, vis, adjR);
            }
        }
        return scc;
    }
};