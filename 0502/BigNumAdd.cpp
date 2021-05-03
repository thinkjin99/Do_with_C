#include<iostream>
#include<algorithm>
using namespace std;
string AddBigNum(string bigNum,string bigNum2){
    int sum = 0;
    string result;
    while(bigNum.empty() != true || bigNum2.empty() != true || sum){
        if(bigNum.empty() != true){
            sum += bigNum.back() - '0';
            bigNum.pop_back();
        }
        if(bigNum2.empty() != true){
            sum += bigNum2.back() -'0';
            bigNum2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum  /= 10;
        // 올림 처리를 해준다.
    }
    reverse(result.begin(),result.end());
    //올림 처리를 위해 뒷자리 부터 연산을 시작했으므로, 뒤집어 준다.
    return result;
}

int main(){
    string num1,num2;
    cin >> num1;
    cin >> num2;
    cout << AddBigNum(num1,num2) << endl;
}