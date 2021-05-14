#include<iostream>
using namespace std;
int FindPrime(int num){
    if (num < 2){
        return 0;
    }
    for(int i = 2; i <= num/2; i++){
          if(num % i == 0) return 0;
    }
    return 1;
}
int main(){
    int n;
    int cnt = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d",&num);
        cnt += FindPrime(num);
    }
    printf("%d",cnt);
}
