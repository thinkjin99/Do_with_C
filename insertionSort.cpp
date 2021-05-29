#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[5] = {3,4,5,1,2};
    for(int i = 1; i < 5; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]){
                swap(arr[j],arr[j - 1]);
            }
            else break;
        }
    }
    for(int i = 0; i < 5; i++) cout << arr[i] << endl;
}