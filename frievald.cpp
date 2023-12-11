#include <bits/stdc++.h>
using namespace std;
vector<int> mat_prodt(vector<vector<int>> x, vector<int> r)
{
    vector<int> ans(x[0].size(), 0);
    for (int i = 0; i < x[0].size(); i++)
    {
        for (int j = 0; j < x[0].size(); j++)
        {
            ans[i] = ans[i] + x[i][j] * r[j];
        }
    }
    return ans;
}
bool frievald(vector<vector<int>> a, vector<vector<int>> b, vector<vector<int>> c)
{
    vector<int> r(a[0].size(), 0);
    for (int i = 0; i < a[0].size(); i++)
    {
        r[i] = rand() % 2;
    }
    vector<int> abr, br, cr;
    br = mat_prodt(b, r);
    abr = mat_prodt(a, br);
    cr = mat_prodt(c, r);
    for (int i = 0; i < br.size(); i++)
    {
        if ((abr[i] - cr[i]) != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> a = {{1, 1}, {1, 1}};
    vector<vector<int>> b = {{1, 1}, {1, 1}};
    vector<vector<int>> c = {{3, 3}, {2, 2}};
    if (frievald(a, b, c))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
