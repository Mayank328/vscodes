#include<bits/stdc++.h>
using namespace std;
void print_vec(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
void gauss_jacobi(vector<vector<int>> v,vector<int> b){
    float x0=0;
    float y0=0;
    float z0=0;
    float x1,y1,z1;
    float tempx=x0;
    float tempy=y0;
    float tempz=z0;
    vector<float> ans;
    while(true){
        x1=(float)(b[0]-v[0][1]*y0-v[0][2]*z0)/(float)(v[0][0]);
        y1=(float)((b[1]-v[1][0]*x0-v[1][2]*z0))/(float)(v[1][1]);
        z1=(float)((b[2]-v[2][1]*y0-v[2][0]*x0))/(float)(v[2][2]);
        if (abs(tempx - x1) <= 0.0000005 && abs(tempy - y1) <= 0.0000005 && abs(tempz - z1) <= 0.0000005)
        {
            break;
        }
        tempx=x1;
        tempy=y1;
        tempz=z1;
        x0=x1;
        y0=y1;
        z0=z1;
    }
    cout<<"x is :"<<x1<<endl;
    cout<<"y is :"<<y1<<endl;
    cout<<"z is :"<<z1<<endl;
}
int main(){
    vector<vector<int>> v;
    vector<int> b;
    vector<int> d;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        int ele;
        cin>>ele;
        d.push_back(ele);
    }
      v.push_back(d);
      d.clear();
    }
    for(int i=0;i<3;i++){
        int ele;
        cin>>ele;
        b.push_back(ele);
    }
    //print_vec(v);
    gauss_jacobi(v,b);
    return 0;
}