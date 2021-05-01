#include<iostream>
using namespace std;
int combination(int n,int r){
    if (r == 1) return n;
    else if (r == n || r < 1) return 1;
    return combination(n-1,r-1) + combination(n-1,r);
}
int main(){
    int r,c;
    cin >> r;
    cin >> c;
    cout << combination(r,c) << endl;
}