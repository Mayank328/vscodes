#include <bits/stdc++.h>
using namespace std;
int mySqrt(float x)
{
    if (x == 0)
    {
        return 0;
    }

    int l = 1;
    int r = x;
    while (l < r - 1)
    {
        int mid = l + (r - l) / 2;
        cout << "value of mid now is " << mid << " ";
        if (x / mid >= mid)
        {
            l = mid;
            cout << "value of l is " << l << " ";
        }
        else
        {
            r = mid - 1;
            cout << "value of r is " << r << " ";
        }
        cout << endl;
    }

    if (x / r >= r)
    {
        return r;
    }
    return l;
}
int main()
{
    // int n;
    // cin >> n;
    // vector<int> nums;
    // for (int i = 0; i < n; i++)
    // {
    //     int ele;
    //     cin >> ele;
    //     nums.push_back(ele);
    // }
    // moveZeroes(nums);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    int x;
    cin >> x;
    cout << mySqrt(x);
    return 0;
}