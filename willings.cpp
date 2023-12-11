#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < m; j += 1)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'B')
            {
                mp[i] = 1;
                mp[j] = 1;
            }
        }
    }
    vector<int> ans;
    vector<int> swap;
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < m; j += 1)
        {
            if (mp[i] != 1 && mp[j] != 1 && grid[i][j] != 'B')
            {
                ans.push_back(stoi(grid[i][j]));
            }
            else if (grid[i][j] != 'B')
            {
                swap.push_back(stoi(grid[i][j]));
            }
        }
    }
    sort(ans.begin(), ans.end());
    sort(swap.begin(), swap.end());
    int max_sum = 0;
    int len = ans.size();
    for (int i = 0; i < len; i += 1)
    {
        if (ans[i] < swap[i] && k > 0)
        {
            max_sum += swap[i];
            k -= 1;
        }
        else
        {
            max_sum += ans[i];
        }
    }
    cout << max_sum;
}