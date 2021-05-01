#include<iostream>
using namespace std;
void over_func(int i){
    cout << i << endl;
}
void over_func(int i, string n){
    cout << i << "  " << n << endl;
}
void over_func(){
    cout << "Only change return" << endl;
}
// void over_func(){
//     cout << "Only change return" << endl; 
//     Only change return type makes problem.
// }
int main(){
    over_func(5);
    over_func(27,"Overloading!!");
    over_func();
}