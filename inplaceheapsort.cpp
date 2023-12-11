#include<bits/stdc++.h>
using namespace std;
void inplaceheapsort(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        int ci = i;
        while(ci>0){
            int pi = (ci - 1) / 2;
            if(arr[pi]>arr[ci]){
                swap(arr[pi],arr[ci]);
                ci = pi;
            }
            else{
                break;
            }
        }
    }
    int size = n;
    while (size >= 1){
    swap(arr[0],arr[size-1]);
    size--;
    int pi = 0;
    while (true)
    {
            int lci = 2 * pi + 1;
            int rci = 2 * pi + 2;
            int mini = pi;
            if (lci < size && arr[mini] > arr[lci])
            {
                mini = lci;
            }
            if (rci < size && arr[mini] > arr[rci])
            {
                mini = rci;
            }
            if (mini == pi)
            {
                break;
            }
            swap(arr[pi], arr[mini]);
            pi = mini;
     }
    }
}
int main(){
    vector<int> arr ={8,4,2,3,1};
    inplaceheapsort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}