#include <bits/stdc++.h>
using namespace std;
class tree
{
    public:
    int data;
    vector<tree *> children;
    tree(int data)
    {
        this->data = data;
    }
};
tree *takeinput()
{
    queue<tree*> q;
    int rootdata;
    cout<<"enter the rootdata";
    cin>>rootdata;
    tree*root=new tree(rootdata);
    q.push(root);
    while(!q.empty()){
        tree*f=q.front();
        q.pop();
        int n;
        cout<<"enter the no of childs";
        cin>>n;
        for(int i=0;i<n;i++){
            int childdata;
            cout<<"enter the childdata";
            cin>>childdata;
            tree*child=new tree(childdata);
            q.push(child);
            f->children.push_back(child);      
            }
}
    return root;
}
void printtree(tree*root){
    queue<tree*>q;
    q.push(root);
    while(!q.empty()){
        tree*f=q.front();
        q.pop();
        cout<<f->data<<":";
        for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data<<" ";
            q.push(f->children[i]);
        }
        cout<<endl;
    }
}
int main()
{
    tree*root=takeinput();
    printtree(root);
    return 0;
}
