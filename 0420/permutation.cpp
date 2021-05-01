#include<iostream>
#include<algorithm>
using namespace std;
void Permutations(char *a, const int k, const int m) { // a[k], ..., a[m]에 대한 모든 순열 생성
    if(k==m){//순열을 출력
        for (int i = 0 ; i <= m; i++) {
            cout << a[i] << " "; 
        }
        cout << endl;
    } 
    else { //a[k:m]에는 하나 이상의 순열이 있다. 이 순열을 순환적으로 생성 for(i = k ; i <= m; i++){
        for(int i = k ; i <= m; i++){
            swap(a[k], a[i]); //묘한 dfs
            Permutations(a, k+1, m);
            swap(a[k], a[i]);
        }
    } 
}

int main(){
    char p[] = {'1','2','3'};
    Permutations(p,0,2);
} 