#include <bits/stdc++.h>
using namespace std;
// class A //  base class declaration.
// {
//     int a;

// public:
//     void display()
//     {
//         cout << "Class A ";
//     }
// };
// class B : public A //  derived class declaration.
// {
//     int b;

// public:
//     void display()
//     {
//         cout << "Class B";
//     }
// };
// int main(){
//     A b;
//     b.display();
// }

// POLYMORPHISM//////
//.................//
// in c++ all floating point constants are treated as doubles.
// pointers and can only access base class members.
// but using a virtual function in base class then using the pointer to access
// the function will call the function of the derived class.
// a pure virtual function consist of only virtully declared functions in the base
// class so we cannot make a object of pure virtual function but a pointer
// can be declared to that class and that pointer if made to point at a derived class
// with the declared function(same name as virtual function) then derived class function
// will be called.
// A pure virtual function is specified by placing "=0" in its declaration;

// ABSTRACTION//
//...........//
// Abstraction in C++ is a process to hide internal details and showing
// functionnality only.
// Abstraction can be done in two ways: Abstract class and Intrface//

// class shape
// {
// public:
//     virtual void draw() = 0;
// };
// class rectangle : shape
// {
// private:
//     int num = 9;
// public:
//     void draw()
//     {
//         cout << "drawing rectangle" << endl;
//         cout<<num<<endl;
//     }
// }r;
// class circle : shape
// {
// public:
//     void draw()
//     {
//         cout << "drawing circle" << endl;
//     }
// };
// int main()
// {
//     rectangle r;
//     // cout << r.num;
//     // circle c;
//     // c.draw();
//     // r.draw();
//     return 0;
// }
// Data Abstraction is a process of providing only
// essential detail to the outside world and hiding the internal details i.e
// showing only essential details in the program.
// It is a programming technique to separate the interface and implementation details
// of the program.
// can be done in two ways: Abstraction using classes and Abstraction using header files
// <math>,<algorithm>,<bitset>,<utility> etc.
// pow(),sort(),builtin_popcount(),pair<int,int> etc...
// Advantages: hidden details are procted from user level error.



// ENCAPSULATION//
//.............//
// Encapsulation is a process to make sure the sensitive data is hidden from the user.
// this is done by making the class variable as private.
// Good practise to make the data as private which improves the security
// Increase the control over the data
// class employee
// {
// private:
//     int salary;

// public:
//     void setsalary(int data)
//     {
//         salary = data;
//     }
//     int getsalary()
//     {
//         return salary;
//     }
// };
// int main()
// {
//     employee e1;
//     e1.setsalary(200000);
//     cout << e1.getsalary() << endl;
// }



// EXCEPTION HANDLING//
//..................//
// It is a process to handle runtimr error.
// exception is an event which is thrown at runtime.
// there are two types of ways for exception handling
// try-catch method and user defined.
//  try{
//      conditions:true
//          cout<<"##"<<endl;
//      condition:false:
//          throw(data);
//  }
//  catch(data){
//      cout<<"####"<<endl;
//  }
// user defined user std::exception
//<exception>
// class myexception: public exception{
//  public:
//  const char*what() const throw(){
//      return "######";
//  }
// }
// try{
//     if(){
//         myexception z;
//         throw z;
//     }
// }
// catch(exception &e){
//     cout<<e.what()<<endl;
// }
