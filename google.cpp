#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    vector<int> c = {0,7,6,9,10,1};
    vector<vector<int>> edges = {{}, {4,3}, {}, {2}, {5},{}};
    queue<pair<int, int>> q;
    q.push({1, 1});
    int ans = c[1];
    vector<int> parent(n + 1, -1);
    parent[1] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int path_len = q.front().second;
        q.pop();
        if (path_len % 2 == 1)
        {
            int curr_node = node;
            vector<int> median;
            median.push_back(c[curr_node]);
            while (parent[curr_node]!= 1) 
            {
                curr_node = parent[curr_node];
                median.push_back(c[curr_node]);
            }
            median.push_back(c[parent[curr_node]]);
            sort(median.begin(), median.end());
            ans += median[median.size() /2];
            median.clear();
        }
        for (auto it : edges[node])
        {
            q.push({it, path_len + 1});
            parent[it] = node;
        }
    }
    cout << ans;
    return 0;
}