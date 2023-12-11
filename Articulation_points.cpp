//articulation points arwe those nodes removal of which breaks the graph into multiple components;
//same concept of bridges
//only difference is that we take the condition if(low[it]>=tin[node] && parent!=-1) as if the that node itself get removed
//then grpah breaks into seperate compoenents and that internal component of that removed node cant remain connected with the other component
//check for parent!=-1 is for the source node cause that can be multiple child the source node and if that gets removed the graph
//breaks into several components;
//if the ndoe is already visited we will then take low[node]=min(low[node],tin[it]) cause

class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer += 1;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child += 1;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<int> mark(V, 0);
        for (int i = 0; i < V; i += 1)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i += 1)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
    }
};