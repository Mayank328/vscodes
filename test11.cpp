#include <bits/stdc++.h>
using namespace std;
void solve(long long k)
{
    int count = 0;
    for (int j = 1; j <= 9; j++)
    {
        long long x = 0;
        for (int m = 1; m <= 10; m++)
        {
            x = x * 10 + j;
            if (x <= k)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    // long long n;
    // cin >> n;
    // long long k;
    // for (long long i = 0; i < n; i++)
    // {
    //     cin >> k;
    //     solve(k);
    // }
    // return 0;
    cout<<103%13;
}