#include<bits/stdc++.h>
using namespace std;
void findLargestSubarray(vector<int> const &nums)
{
    int x = 0;
    int y = 0;
    int tempx=0;
    int tempy=0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        x=i;
        cout<<"x is now: "<<x<<endl;
        int mn = nums[i];
        int mx = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            mn = min(mn, nums[j]);
            mx = max(mx, nums[j]);
            if ((mx - mn) == (j - i))
            {
                if(y<j){
                    y=j;
                    cout<<"y is now: "<<y<<endl;
                }
            }
        }
        if((y-x)>=(tempy-tempx)){
            tempx=x;
            tempy=y;
            cout<<"temp x and temp y is now: "<<tempx<<" "<<tempy<<endl;
        }
    }
    cout<<tempx<<" "<<tempy<<endl;
    vector<int> res;
    for (int i = tempx; i <= tempy; i++)
    {
        res.push_back(nums[i]);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}
// int main(){
//     vector<int> v;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     findLargestSubarray(v);
//     return 0;
// }

int main()
{    vector<int> v;
    v.push_back(7);
    v.push_back(10);
    v.push_back(19);
    cout<<v.size()<<v[0];
    v.resize(2);
    cout<<v.size();
    cout<<v[0];
    cout<<v[1];

    return 0;
}