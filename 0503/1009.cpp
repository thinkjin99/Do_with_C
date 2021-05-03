#include<iostream>
using namespace std;
int main(){
    int cnt,a,b;
    cin >> cnt;
    int *result = new int[cnt];
    for(int c = 0; c < cnt; c++){
            int num = 1;
            cin >> a >> b;
            if(a % 10 == 0) {
                result[c] = 10;
                continue;
            }
            for(int i = 0; i < b; i++){
                num = (a * num) % 10;
            }
            result[c] = num;
    }
    for(int i = 0; i < cnt; i++ ){
        cout << result[i] << endl;
    }
}