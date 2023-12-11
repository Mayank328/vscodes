#include <bits/stdc++.h>
using namespace std;
// vector<int> scs(vector<int> &a,vector<int> &b,int n,int m,vector<int> &s){
//     int dp[1002][1002];
//     for(int i=0;i<n+1;i+=1){
//         for(int j=0;j<m+1;j+=1){
//             if(i==0 || j==0){
//                 dp[i][j]=0;
//             }
//         }
//     }
//     for(int i=1;i<n+1;i+=1){
//         for(int j=1;j<m+1;j+=1){
//             if(a[i]==b[j]){
//                 dp[i][j]=dp[i-1][j-1]+1;
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     int i=n;int j=m;
//     while(i>0 && j>0){
//         if(a[i-1]==b[j-1]){
//             s.push_back(a[i-1]);
//             i--;
//             j--;
//         }
//         else if(dp[i-1][j]>dp[i][j-1]){
//             s.push_back(a[i-1]);
//             i--;
//         }
//         else{
//             s.push_back(b[j-1]);
//             j--;
//         }
//     }
//     while(i>0){
//          s.push_back(a[i-1]);
//          i--;
//     }
//     while(j>0){
//         s.push_back(b[i-1]);
//         j--;
//     }
//     return s;
// }
int main(){
    int n=3;
    vector<int> b={1,2,3};
    int m=2;
    vector<int> a={4,1};
    vector<int> s1;
    vector<int> s2;
    int max_ele_a=INT_MIN;
    int min_ele_a=INT_MAX;
    for(auto i:a){
        max_ele_a=max(max_ele_a,i);
        min_ele_a=min(min_ele_a,i);
    }
    int max_ele_b=INT_MIN;
    int min_ele_b=INT_MAX;
    for(auto i:b){
        max_ele_b=max(max_ele_b,i);
        min_ele_b = min(min_ele_b, i);
    }
    if(max_ele_a>max_ele_b){
        s1=a;
        for(auto j:b){
            s1.push_back(j);
        }
    }
    else{
        s1=b;
        for(auto j:a){
            s1.push_back(j);
        }
    }
    if (min_ele_a < min_ele_b)
    {
        s2 = a;
        for (auto j : b)
        {
            s2.push_back(j);
        }
    }
    else
    {
        s2 = b;
        for (auto j : a)
        {
            s2.push_back(j);
        }
    }
    for(int i=0;i<s1.size();i+=1){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
    int max_ele=INT_MIN;
    int max_sum=0;
    int min_ele = INT_MAX;
    int min_sum = 0;
    for(int i=0;i<a.size()+b.size();i+=1){
        for(int j=0;j<=i;j+=1){
            max_ele=max(max_ele,s1[j]);
            min_ele=min(min_ele,s1[j]);
        }
        max_sum+=max_ele;
        min_sum+=min_ele;
    }
    int ans1 = max_sum - min_sum;
    max_ele = INT_MIN;
    max_sum = 0;
    min_ele = INT_MAX;
    min_sum = 0;
    for (int i = 0; i < a.size() + b.size(); i += 1)
    {
        for (int j = 0; j <= i; j += 1)
        {
            max_ele = max(max_ele, s2[j]);
            min_ele = min(min_ele, s2[j]);
        }
        max_sum += max_ele;
        min_sum += min_ele;
    }
    int ans2=max_sum-min_sum;
    int ans=max(ans1,ans2);
    cout<ans<<endl;
     return 0;
}