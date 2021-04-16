#include<iostream>
using namespace std;
int binary_search(const int (&ref)[10],int now,int before,int num){
    if (ref[now] == num) return now;
    if (ref[now] <= num) {
        int gap = abs((now - before) / 2);
        if (!gap) gap++;
        return binary_search(ref,now + gap,now,num);
    }
    else return binary_search(ref,now / 2,now,num);
    return -1;
}
int main(){
    int arr[] = {0,4,6,8,10,14,22,30,44,70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num;
    for (int i = 0; i < size; i++){
        cout << "숫자: " << arr[i] << " 순서: " << binary_search(arr,(size-1) / 2,0,arr[i]) << endl;
    }
}