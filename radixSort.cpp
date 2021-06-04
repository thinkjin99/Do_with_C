#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    int biggest;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[i] = num;
        biggest = (biggest > num) ? biggest : num;
    }   
    for(int i = 1; biggest / i > 0; i *= 10){
        queue <int> q[10];
        for(int k = 0; k < n; k++){
            int index = (arr[k] / i) % 10;
            q[index].push(arr[k]);
        }
        int cnt = 0;
        for(int j = 0; j < 10; j++){
            while(q[j].empty() != true){
                arr[cnt++] = q[j].front();
                q[j].pop();
            }
        }
        for(int k = 0; k < n; k++){
            cout << arr[k] << "\t";
        }
        cout << endl;
    }
}
    