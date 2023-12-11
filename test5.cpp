#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n,m;
        cin>>n>>m;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll j=0;j<n;j++){
            ll ele;
            cin>>ele;
            pq.push(ele);
        }
        for(ll j=0;j<m;j++){
            ll ele;
            cin>>ele;
            pq.pop();
            pq.push(ele);
        }
        ll sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}