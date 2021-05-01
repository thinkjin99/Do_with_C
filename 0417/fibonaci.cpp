#include<iostream>
using namespace std;
int main(){
    int fiboNums[3] = {0,1,0};
    int num;
    cin >> num;
    for (int i = 0; i < num; i++){
        fiboNums[2] = fiboNums[1];
        fiboNums[1] = fiboNums[0];
        fiboNums[0] = fiboNums[1] + fiboNums[2];
    }
    cout << fiboNums[0] << endl;
}