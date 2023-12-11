vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    for (int i = 0; i < M; i += 1)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<pair<int, int>> q;
    vector<int> dist(N, 1e8);
    q.push({src, 0});
    dist[src] = 0;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        for (auto it : adj[node.first])
        {
            int v = it;
            if (node.second + 1 < dist[v])
            {
                dist[v] = dist[node.first] + 1;
                q.push({v, dist[v]});
            }
        }
    }
    for (int i = 0; i < dist.size(); i += 1)
    {
        if (dist[i] == 1e8)
        {
            dist[i] = -1;
        }
    }
    return dist;
}