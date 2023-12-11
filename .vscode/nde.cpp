#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < 2*n; i++)
    {
        arr[i] = i;
        cout << arr[i] << endl;
        int sz = sizeof(arr) / sizeof(arr[0]);
        cout << sz;
    }
    int sz = sizeof(arr) / sizeof(arr[0]);
    cout << sz;
    cout<<arr[8];
    return 0;
}