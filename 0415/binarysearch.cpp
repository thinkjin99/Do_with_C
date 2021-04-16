#include<iostream>
using namespace std;
int binary_search(const int (&ref)[10],int start,int end,int num){
    int middle = (end + start) / 2;
    if (ref[middle] == num) return middle;
    if (ref[middle] <= num) return binary_search(ref,middle+1,end,num);
    else return binary_search(ref,start,middle-1,num);
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,10,12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num;
    cout << "Input: ";
    // cin >> num;
    cout << binary_search(arr,0,size,10) << endl;
}