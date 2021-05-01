#include<iostream>
using namespace std;
int pointer(int* const num){
    return ++(*num);
}
int reference(int& num){
    return ++num;
}
int main(){
    int num = 10;
    int* const p_num = &num;
    const int &n = num;
    // int num2 = 20;
    // p_num = &num2;
    cout << pointer(p_num) << endl;
    cout << reference(num) << endl;
}