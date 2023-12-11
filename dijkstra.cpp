vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({S, 0});
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    while (!pq.empty())
    {
        int v = pq.top().first;
        int wt = pq.top().second;
        pq.pop();
        for (auto i : adj[v])
        {
            if (dist[v] + i[1] < dist[i[0]])
            {
                dist[i[0]] = dist[v] + i[1];
                pq.push({i[0], dist[i[0]]});
            }
        }
    }
    return dist;
}