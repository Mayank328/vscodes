#include <bits/stdc++.h>
using namespace std;
void print_vec(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void permutation(string s, int ind)
{
    if (ind == 5)
    {
        cout << s << endl;
        return;
    }
    s += '0';
    permutation(s, ind + 1);
    s.pop_back();
    s += '1';
    permutation(s, ind + 1);
}
int main()
{
    vector<int> v={1,2,3,4,5,6};
    int n=v.size();
    int sum=accumulate(v.begin(),v.end(),0);
    cout<<sum;
    return 0;
}