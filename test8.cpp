#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    return (n*n-n+2)/2;
}
void solve(int n,int k){
    int i,j,digit=1;
    for ( i=k ; i>0 ; i--)
    {
        if (f(i)+k-i<=n)
            break;
    }
    for (j=0;j<i;j++)
    {
        digit+=j;
        cout<<digit<<' ';
    }
    for ( ; j<k;j++)
    {
        digit+=1;
        cout<<digit<<' ';
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>k>>n;
        solve(n,k);
        cout<<endl;
    }
    return 0;
}