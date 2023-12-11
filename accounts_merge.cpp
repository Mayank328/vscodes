class dsu
{
    vector<int> rank, parent, size;

public:
    dsu(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i += 1)
        {
            parent[i] = i;
        }
    }
    int fup(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = fup(parent[node]);
    }
    void ur(int u, int v)
    {
        int ulp_u = fup(u);
        int ulp_v = fup(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        else if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void us(int u, int v)
    {
        int ulp_u = fup(u);
        int ulp_v = fup(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if (size[ulp_v] < size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mp;
        int n = accounts.size();
        dsu ds(n);
        for (int i = 0; i < n; i += 1)
        {
            for (int j = 1; j < accounts[i].size(); j += 1)
            {
                string email = accounts[i][j];
                if (mp.find(email) == mp.end())
                {
                    mp[email] = i;
                }
                else
                {
                    ds.us(i, mp[email]);
                }
            }
        }
        vector<string> mailbox[n];
        for (auto it : mp)
        {
            string mail = it.first;
            int mailnode = it.second;
            int node = ds.fup(mailnode);
            mailbox[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i += 1)
        {
            if (mailbox[i].size() == 0)
                continue;
            sort(mailbox[i].begin(), mailbox[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mailbox[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};