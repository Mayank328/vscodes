#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(string s, ll n)
{
    vector<int> prefix(n, 0), suffix(n, 0);
    set<int> st;
    for (int j = 0; j < n; j++)
    {
        st.insert(s[j]);
        prefix[j] = st.size();
    }
    st.clear();
    for (int j = n - 1; j >= 0; j--)
    {
        st.insert(s[j]);
        suffix[j] = st.size();
    }
    int ans = 0;
    int maxans = 0;
    for (int j = 0; j < n - 1; j++)
    {
        ans = prefix[j] + suffix[j + 1];
        maxans = max(ans, maxans);
    }
    cout << maxans << endl;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
    return 0;
}