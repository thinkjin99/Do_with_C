#include<iostream>
using namespace std;
int main(){
    int money;
    cin >> money;
    money = 1000-money;
    int change[] = {500,100,50,10,5,1};
    int cnt = 0;
    for(int i = 0; i < 6; i++){
        cnt += money / change[i];
        money = money % change[i]; 
    }
    cout << cnt << endl;
}