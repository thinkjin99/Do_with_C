#include<iostream>
using namespace std;
const int* n;
int cnt = 0;
int rows[15];

bool isPossible(int coLevel){
    for(int i = 0; i < coLevel; i++){
        if(rows[coLevel] == rows[i] || abs(i-coLevel) == abs(rows[coLevel] - rows[i])) return false;
    }
    return true;
}

void queen(int coLevel){ //column의 단계를 의미한다.
    if(coLevel == *n) {
        cnt++;
        return;
    }
    else{
        for(int i = 0; i < *n; i++){
            rows[coLevel] = i;
            if(isPossible(coLevel)) queen(coLevel + 1);
        }
    }
}

int main(){
    int num; cin >> num;
    n = &num;
    queen(0);
    cout << cnt << endl;
}