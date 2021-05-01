#include<iostream>
using namespace std;
int Fibo(int n){
    int fiboTerms[2] = {1,1};
    int result = 1;
    for (int i = 2; i < n; i++){
        result = fiboTerms[0] + fiboTerms[1];
        fiboTerms[1] = fiboTerms[0];
        fiboTerms[0] = result;
    }
   return result;
}
   