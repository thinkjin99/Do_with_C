#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int m,n;
    cin >> m;
    cin >> n;
    bool* isPrime = new bool[n + 1];
    for(int i = 2; i <= n;  i++) isPrime[i] = true;
    
    for(int i = 2; i <= sqrt(n); i++){
        for(int j = i*i; j <= n; j+=i){
            if(isPrime[j] == true) isPrime[j] = false;
        }
    }

    int sum = 0;
    int firstPrime = -1;
    for(int i = m; i <= n; i++){
        if(isPrime[i] == true){
            sum += i;
            if(firstPrime < 0) firstPrime = i;
        }
    }
    if(firstPrime > 0) {
        cout << sum << "\n";
        cout << firstPrime << "\n";
    }
    else cout << -1 << "\n";
}