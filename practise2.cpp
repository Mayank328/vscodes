#include <bits/stdc++.h>
using namespace std;
void print_vec(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
void All_Permutations(vector<vector<int>> &ans,vector<int> &v,vector<int> a,map<int,int> &mp,int n){
    if(n<=0){
        ans.push_back(v);
        return;
    }
    for (auto i = mp.begin(); i != mp.end(); i++){
        if(i->second<=0){
            continue;
        }
        v.push_back(i->first);
        i->second--;
        All_Permutations(ans,v,a,mp,n-1);
        v.pop_back();
        i->second++;
    }
}
int main(){
    vector<int> a={1,1,2};
    vector<int> v;
    vector<vector<int>> ans;
    map<int,int> mp;
    for(int i=0;i<a.size();i+=1){
        mp[a[i]]++;
    }
    All_Permutations(ans,v,a,mp,a.size());
    print_vec(ans);
    return 0;
}