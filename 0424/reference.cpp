#include<iostream>
using namespace std;
int main(){
    int a[5] = {1,2,3,4,5};
    int& b = *a;
    cout << b << endl;
}