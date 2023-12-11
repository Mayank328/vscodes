#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long q, n;
    cin >> q;
    while (q--)
    {
        cin >> n;
        long long c=0;
        vector<long long> v(n), a(n), b(n);
        for (long i = 0; i < n; i++)
            cin >> v[i];
        a[0] = v[0];
        for (long i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + v[i];
        }
        b[n - 1] = v[n - 1];
        for (long i = n - 2; i >= 0; i--)
        {
            b[i] = b[i + 1] + v[i];
        }
        for (long i = 0; i < n - 1; i++)
        {
            c = max(c, __gcd(a[i], b[i + 1]));
        }
        cout << c << endl;
    }
}