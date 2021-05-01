#include<iostream>
#include<algorithm>
using namespace std;
int GCD(int a, int b){
    if(a % b ==0) return b;
    return GCD(b,a % b);
}
//최소 공배수는 a*b // GCD
int main(){
    int a,b;
    cin >> a;
    cin >> b;
    if(a < b) swap(a,b);
    int gcd = GCD(a,b);
    cout << gcd << endl;
    cout << a / gcd * b << endl;
}