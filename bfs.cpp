#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int edges, vector<int> adj[])//vector<int> adj[] is a list of vectors where at index i vector containing the connected nodes with i;
{
    int vis[edges] = {0};//visited array
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])//loop to visit all the connected vertices at the given node index
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
//Time complexities of bfs is "O(N)+O(2*No of edges)" cause queue will contain all the nodes and inside for loop with run on all the edges of the node
int main(){

}