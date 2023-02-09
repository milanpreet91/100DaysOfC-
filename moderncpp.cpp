#include <iostream>
#include <vector>
#include <chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

int func(int i){
    cout << "func(int) called and sent " << i << endl;
    return i+2;
}

void func(int* i) {
    cout << "func(int*) called " << i << endl;
}
//if added below func, nullptr keyword gets confused 
//and gives ambiguous error
/*void func(char* i) {
    cout << "func(char*) called" << endl;
}*/

int main()
{
    int x = 7.7; //legal with compiler warning, int truncated to double
    int y{8};
    auto autovar{8}; //<==> int a{8}
    //int y{8.8} // illegal
    string s1 ="Hello";
    int arr[7] = {1,2,3,4};
    string s2{'h','e','l','l','o'};
    char s3[]{'h','e','l','l','o'};

    cout << "x is " << x << " arr is " <<arr[3] << " y is " << y << " s1 is " << s1 << " s2 is " << s2 << " s3 is " << s3[6] <<endl;

    vector<int> v = {1,2,3,4,5};
    //vector<int> v{1,2,3,4,5}; //new c++11
    for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
        cout << *it << endl;
    }
    //above and below are same
    //auto ueful with complicaed types
    //compiler deduces the type and replaces for us
    cout << endl;
    for (auto it1 = v.begin(); it1 != v.end();it1++) {
        //*it1 += 2;
        cout << *it1 << endl;
    }
    cout << endl;

    for (auto& it2 : v){
        it2 += 2;
        cout << it2 <<endl;
        //v.push_back(140);
    }
        cout << endl;

    for (auto it2 : v){
        cout << it2 <<endl;
    }
    seconds(360000000);
    //nullptr keyword: compatible with any type of pointer
    func(nullptr);//calls func(int*) not func(int)
    //func(NULL); //NULL: preprocessor macro, defined as zero, type ot specified, 
    //different results with different compiler
    //const int& a = func(2);
    const auto& a = func(2); // have to specify const and 
    //reference as auto doesnt take them into account
    // while figuring out type
    //func returning reference to const "type" 
    //a = 10;
    cout << a << endl;
    auto radix{2};
    //lambdas are nameless functions, defined inline
    //function inside a function -> local function
    //lambda expressions are more convinient than traditional function args
    //useful for passing as function call args 
    //or function return types
    //traditional way was: function pointers(c) and functors(c++)
    //functors: class defining function call operators
    //function name -> []
    //function args
    //if single statement inside function, 
        //dont specify return type, compiler deduces
    //if not, specify as trailing
    //c++14, compiler deduces if multiple statements but they return same return type
    //[](int i) { return 2*i; }// return type deduced
    //[](int i)->int {cout << i<< endl; return 2*i;} //return type specified
    //trailing return type not needed in c++14
    //helpful as std library functions like sorting, serahcing
    int even_nums= count_if(v.begin(),v.end(),
                    [radix](int n) { return(n%radix == 0);});
    cout << even_nums << endl;
    //f([a](){ return (a%2 == 0);});
}
