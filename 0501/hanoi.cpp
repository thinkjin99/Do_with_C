#include<iostream>
#include<math.h>
using namespace std;
void Hanoi(int n,int start, int via, int end){
    if(n == 1){
        cout << start << " " << end << '\n';
        return;
    }
    Hanoi(n - 1,start,end,via);
    cout << start << " " << end << '\n';
    Hanoi(n - 1,via,start,end);
}

int main(){
    int n;
    scanf("%d",&n);
    cout << int(pow(2,n) - 1) << '\n';
    Hanoi(n,1,2,3);
}