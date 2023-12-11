#include <bits/stdc++.h>
using namespace std;
class sgtree
{
public:
    vector<int> seg;
    sgtree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<int> &arr, int ind, int low, int high)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * ind + 1, low, mid);
        build(arr, 2 * ind + 2, mid + 1, high);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int querry(int ind, int low, int high, int l, int r)
    {
        // no overlap;
        if (l > high || r < low)
            return INT_MAX;
        // complete overlap;
        if (low >= l && r >= high)
            return seg[ind];
        // partial overlap;
        int mid = (low + high) >> 1;
        int left = querry(2 * ind + 1, low, mid, l, r);
        int right = querry(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> arr[i];
    }
    sgtree seg1(n);
    seg1.build(arr, 0, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int minele = seg1.querry(0, 0, n - 1, l, r);
            cout << minele << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            seg1.update(0, 0, n - 1, i, val);
            cout << seg1.seg[0] << endl;
        }
    }
}