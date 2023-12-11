#include <bits/stdc++.h>
using namespace std;

class parent
{
    string mother = "Mary";
    string father = "George";

public:
    void get_parent()
    {
        cout << "mother :" << mother << endl;
        cout << "father :" << father << endl;
    }
};
class child : public parent
{
    string name;

public:
    child(string c)
    {
        name = c;
    }
    void get_detail()
    {
        get_parent();
        cout << name << "name :" <<name<<endl;
    }
};
int main()
{
    parent p;
    child c("josh");
    c.get_detail();
    return 0;
}