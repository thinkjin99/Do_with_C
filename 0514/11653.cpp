#include<iostream>
using namespace std;
int FindPrime(int PrimeNum, int num){
    for(int i = PrimeNum + 1; i <= num/2; i++){
        bool is_Prime = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0) {
              is_Prime = false;
              break;
            }
            if(is_Prime) return i;
        }
    }
    return num;
}

int main(){
    int num;
    scanf("%d",&num);
    int primeNum = 2;
    while (num >= 2){
     if (num % primeNum == 0){
         num = num / primeNum;
         cout << primeNum << "\n";
     }
     else{
         primeNum = FindPrime(primeNum,num);
         }
    }
}
