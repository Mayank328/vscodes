#include <bits/stdc++.h>
using namespace std;
int main()
{
    int dp[3][200];
    for (int i = 0; i < 200; i++)
    {
        dp[0][i] = dp[1][i] = dp[2][i] = 1000;
    }
    int v[200];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // dp[i][j]: i denotes ith day & j denotes either rest,contest or gym;
    // at day 0 we can always rest;
    dp[0][0] = 1;
    // if we can do contest on day zero;
    if (v[0] == 1 || v[0] == 3)
    {
        dp[1][0] = 0;
    }
    // if we can do gym on day zero
    if (v[0] == 2 || v[0] == 3)
    {
        dp[2][0] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        // we can always rest on any day
        dp[0][i] = 1 + min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1]));
        // check if we can give a contest on that day;
        if (v[0] == 1 || v[0] == 3)
        {
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
        }
        // check of we can do gym on that day;
        if (v[0] == 2 || v[0] == 3)
        {
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
    }
    cout << min(dp[0][n], min(dp[1][n], dp[2][n]));
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int dp[3][200];
//     for (int i = 0; i < 200; i++)
//     {
//         dp[0][i] = dp[1][i] = dp[2][i] = 1000;
//     }
//     int v[200];
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     // dp[i][j]: i denotes ith day & j denotes either rest,contest or gym;
//     // it stores number of days rested till jth day;
//     // at day 0 we can always rest;
//     dp[0][0] = 1;
//     // if we can do contest on day zero;
//     if (v[0] == 1 || v[0] == 3)
//     {
//         dp[1][0] = 0;
//     }
//     // if we can do gym on day zero
//     if (v[0] == 2 || v[0] == 3)
//     {
//         dp[2][0] = 0;
//     }
//     for (int i = 1; i < n; i++)
//     {
//         // rest on any day
//         dp[0][i] = 1 + min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1]));
//         //  contest on that day;
//         if (v[0] == 1 || v[0] == 3)
//         {
//             dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
//         }
//         //  gym on that day;
//         if (v[0] == 2 || v[0] == 3)
//         {
//             dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
//         }
//     }
//     cout << min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1]));
//     return 0;
// }