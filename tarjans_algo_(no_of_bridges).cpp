//tarjan's algporithm for finding the number of bridges in a graph..
//the edge which when removes break the graph into 2 or more components is knowe as bridges
//in this algorithm we need to take tin array and low array 
//tin denote the time of insertion and low denotes the minimum time of insertion of all theb adjacent nodes
//if the component is connected then low time of all the nodes of that component will get updated to lowest insertion time.
//and tin of all the node will remain the same.
// for inplementing the above,after coming out of the dfs just take the low[node]=min(low[node],low[it]) then check 
//if the low[it]> tin[node] to check if the curr adjacent node is the part of the internal component or not as
//if it were a part of the internal component it would have met someone from the internal component during its dfs and its
//low[it] would have got updated to the lowest insertion time of the internal component...

class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer += 1;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};