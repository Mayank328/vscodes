#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], vector<int> &vis, vector<int> &dfs_trvls, int node)
{
    vis[node] = 1;
    dfs_trvls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, vis, dfs_trvls, it);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfs_trvls;
    int start = 0;
    dfs(adj, vis, dfs_trvls, start);
    return dfs_trvls;
}
//space complexity: O(N)(visted vector)+O(N)(dfs_trvls for storing)+O(N)(recursion call stack);
//time complexity: O(N)(recursion on all nodes)+O(2E)(total summation of degrees of all nodes);
int main(){
    
}