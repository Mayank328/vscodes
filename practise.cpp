#include <bits/stdc++.h>
using namespace std;
void print_vec(vector<vector<char>> v){
    for(int i=0;i<3;i+=1){
       for(int j=0;j<3;j+=1){
        cout<<v[i][j]<<" ";
       }
       cout<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> v;
        vector<char>d;
        for (int i = 0; i < 3; i++)
        {
            char a, b, c;
            cin >> a >> b >> c;
            d.push_back(a);
            d.push_back(b);
            d.push_back(c);
            v.push_back(d);
            d.clear();
        }
        bool chk = true;
        if (chk)
        {
            for (int i = 0; i < 3; i++)
            {
                if (v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0] != '.')
                {
                    cout << v[i][0] << endl;
                    chk = false;
                    break;
                }
            }
        }
        if (chk)
        {
            for (int i = 0; i < 3; i++)
            {
                if (v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] != '.')
                {
                    cout << v[0][i] << endl;
                    chk = false;
                    break;
                }
            }
        }
        if (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.')
        {
            cout << v[0][0] << endl;
            continue;
        }
        if (v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[1][1] != '.')
        {
            cout << v[1][1] << endl;
            continue;
        }
        if (chk)
        {
            cout << "DRAW" << endl;
        }
    }
}