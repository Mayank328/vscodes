// #include<bits/stdc++.h>
// using namespace std;
// void helper(string s,map<int,int> mp){
//     int sum=0;
//     int ans=0;
//     for(int i=0;i<s.length();i+=1){
//         sum+=(int)s[i];
//         cout<<sum<<endl;
//         auto it=mp.find(sum);
//         if(it!=mp.end()){
//             ans+=it->second;
//             sum=0;
//         }
//     }mp[i]=sum;
//     cout<<ans;
// }
// map<int,int > mp;
// for(auto &i:v){
//     for(auto &j:i){
//         sum+=(int)j;
//     }
//     mp[sum]=i;
// }
// one =322;
// mp[322]=1;
// int main()
// {
//     queue<btnode*> q;
//     q.push(root1);
//     q.push(root2);
//     while(!q.empty()){
//         btnode*f1=q.top();
//         q.pop();
//         btnode*f2=q.top();
//         q.pop();
//         if(f1->left!=NULL && f2->left!=NULL){
//             q.push(f1->left);
//             q.push(f2->left);
//             if(f1->val!=f1->val){
//                 return false;
//             }
//         }
//         if (f1->right != NULL && f2->right != NULL)
//         {
//             q.push(f1->right);
//             q.push(f2->right);
//             if (f1->val != f1->val)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
#include <bits/stdc++.h>
using namespace std;

static int t[1001][1001];

void lcs(string &text1, string &text2, int n, int m)
{

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (text1[i - 1] == text2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
}

string print_lcs(string &text1, string &text2, int n, int m)
{
    string s ="";

    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            s += text2[j - 1];
            i--;
            j--;
        }
        else if (t[i - 1][j] > t[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string text1 = "abc";
    string text2 = "def";

    int n = text1.size();
    int m = text2.size();
    lcs(text1, text2, n, m);

    string common = print_lcs(text1, text2, n, m);

    cout << common << endl;

    return 0;
}