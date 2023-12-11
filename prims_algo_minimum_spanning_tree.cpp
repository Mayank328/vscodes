#include<bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> vis(V, 0);
    //min heap is used to keep the min wt edge at the top of the queue 
    //so that every time element is retrieved edge with min weight comes out
    //also in the queue {weight,node} should be the order so that queue will get arrange according the
    //min weight each time a pair gets pushed....
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int ewt = it[1];
            if (!vis[adjnode])
            {
                pq.push({ewt, adjnode});
            }
        }
    }
    return sum;
}