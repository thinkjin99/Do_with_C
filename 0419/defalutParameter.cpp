#include<iostream>
using namespace std;
int foo(int num1 = 10, int num2 = 90, int num3 = 20){
    return num1 + num2 + num3;
}
int main(){
    cout << foo(100) << endl;
}