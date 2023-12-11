vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i += 1)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    // for(int i=1;i<=n;i+=1){
    //     cout<<i<<" ";
    //     for(auto it:adj[i]){
    //         cout<<"{"<<it.first<<" "<<it.second<<"}"<<" ";
    //     }
    //     cout<<endl;
    // }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 0});
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i += 1)
    {
        parent[i] = i;
    }
    while (!pq.empty())
    {
        int curr_node = pq.top().first;
        int wt = pq.top().second;
        pq.pop();
        for (auto it : adj[curr_node])
        {
            if (dist[curr_node] + it.second < dist[it.first])
            {
                parent[it.first] = curr_node;
                dist[it.first] = dist[curr_node] + it.second;
                pq.push({it.first, dist[it.first]});
            }
        }
    }
    if (dist[n] == INT_MAX)
    {
        return {-1};
    }
    vector<int> ans;
    ans.push_back(n);
    while (parent[n] != n)
    {
        ans.push_back(parent[n]);
        n = parent[n];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}