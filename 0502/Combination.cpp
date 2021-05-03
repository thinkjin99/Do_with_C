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

string combination(long long n,long long r,string (*arr)[101]){
    if (r == n || r == 0) return "1";
    else if(arr[n][r] != "") return arr[n][r];
    string sum =  AddBigNum(combination(n-1,r-1,arr),combination(n-1,r,arr));
    //큰 수를 더 해주기 위해 string으로 변환 한 후 한자리 씩 연산
    arr[n][r] = sum;
    return sum;
}

int main(){
    long long r,c;
    string arr[101][101];
    scanf("%lld",&r);
    scanf("%lld",&c);
    cout << combination(r,c,arr) << endl;
}