#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,s,r;
    cin>>n>>s>>r;
    cout<<s-r<<" ";
    --n;
    for(int i=1;i<=r%n;++i){
        cout<<r/n+1<<" ";
    }
    for(int i=1;i<=n-r%n;++i){
        cout<<r/n<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
    solve();
    }
    return 0;
}