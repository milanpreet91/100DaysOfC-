#include <iostream>
#include <vector>
#include <chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

int func(int&& val){ // rvalue reference:::it means function only takes rvalue
//cannot send lvalue to this func argument
    cout << val << endl;
    return val;
}
void func(vector<int> v){
    cout << "in func, v size is " << v.size() << endl;
}

int main()
{
   //lvalue reference:
    //reference to a variable that has an address
    //example: 
    //int x = 5; int& ref = x;
   //rvalue reference 
    //example: function return value
    //reference to a literal that 
    //doesn't have an address
   //reference is a pointer with different representation
   //int& y = 4 // illegal, y is rvalue reference and it cannot reference lvalue
   int x = 4; // x is rvalue, 1 is lvalue
   int& y = x; // legal ==> int* y = &x
   int a = 3; // reference can be used to change the value placed at address of x <==> *y = 3;
   int b = func(3);
   //x = lvalue
   //func(n) is returning some value which has no real address ->> rvalue
   int c{2};
   func(move(c)); // move casts lvalue to rvalue, 
   //use move if you want to pass lvalue to a function only accepting rvalue
   //use move if you want to pass lvalue to a function and destroy its address from original place
   //useful when we want to pass some variable to a function and not use it further in caller function
   func(2);
   //traditional C++: passing an argument always copies it
   //modern c++: if argument is rvalue, it can be moved permanently into the function
   //example: vector
   //if passing vector as value to a function, converting it from lvalue to rvalue moves it permanently
   //this conversion can be done by casting it using "std::move"
   //if we pass lvalue, it will just be copied
   //if we pass rvalue, it will be moved
   vector<int> v(1000000);
   //func(v);//pass by lvalue, only copying happens here. entire v is copied into func
   func(std::move(v)); //pass by rvalue, this moves entire vector to function
   cout << "in main, v size is " << v.size() << endl;
}
