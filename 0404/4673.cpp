#include <iostream>
using namespace std;
const int length = 10000;
int not_self_num(int num){
    int sum = num;
    for(int i = 0; num > 0; num /= 10, i++){
        sum += num % 10;
    }
    return sum;
}
int main(){
    bool is_self[length] = {false,};
    for(int i = 0; i < length; i++){
        int index = not_self_num(i);
        if (index > length) continue;
        is_self[index] = true;
    }
    for(int j = 0; j < length; j++){
        if(!is_self[j]){
            cout << j << endl;
        }
    }
    return 0;
}
