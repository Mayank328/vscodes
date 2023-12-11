#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
    int a;
    int b;
    int *c;
    void setdata(int x, int y, int z)
    {
        a = x;
        b = y;
        *c = z;
    }
    A()
    {
        c = new int;
    }
    A(A &a1){
        a=a1.a;
        b=a1.b;
        c=new int;
        *c=*(a1.c);
    }
    void showdata()
    {
        cout << "A is:" << a << endl;
        cout << "B is:" << b << endl;
        cout << "C is:" << *c << endl;
    }
};
int main()
{
    A a1;
    a1.setdata(1,2,3);
    a1.showdata();
    A a2 = a1;
    a2.showdata();
    return 0;
}