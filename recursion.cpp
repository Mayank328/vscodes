#include <bits/stdc++.h>
using namespace std;
void All_subseq(int ind, vector<int> &v, vector<int> a, int n,int k,int &sum)
{
    if (ind == n)
    {
        if(sum==k){
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    v.push_back(a[ind]);
    sum+=a[ind];
    All_subseq(ind + 1, v, a, n,3,sum);
    v.pop_back();
    sum-=a[ind];
    All_subseq(ind + 1, v, a, n,3,sum);
}
int main()
{
    vector<int> a = {3, 2, 1,1,2,1};
    vector<int> v;
    int sum=0;
    int n = a.size();
    All_subseq(0, v, a, n,3,sum);
    return 0;
}