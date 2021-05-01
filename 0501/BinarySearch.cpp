#include<iostream>
using namespace std;
int binary_search(int *arr,const int num, const int left,const int right,int& count){ //ppt참조
    if(left <= right){
        int middle = (left + right) / 2;
        //절반을 탐색하고 또 절반을 탐색하는 방식이다.
        //10칸 짜리 배열의 경우 5 -> 7 -> 8 -> 9 이런 식으로 탐색하고 종료된다.
        //log n의 복잡도를 띈다.
        count++;
        if(num > arr[middle]) return binary_search(arr,num,middle + 1,right,count);
        //return을 붙이고 함수를 호출해야 하는 이유
        //return 키워드를 제거하고 함수를 호출하면 함수의 리턴 값이 계속해서 초기화 된다.
        //함수에 return 키워드를 추가하고 재귀를 하면 최초에 리턴했던 값만을 전달 할 수 있다.
        else if(num < arr[middle]) return binary_search(arr,num,left,middle - 1,count);
        return middle;
    }
    else return -1;
}

int main(){
    int len = 30;
    cin >> len;
    int *arr = new int[len];
    for (int i = 0; i < len; i++){
        cin >> arr[i];
    }
    int num = 5;
    cin >> num;
    int count = 0;
    int result = binary_search(arr,num,0,len-1,count);
    cout << "result: " << result << endl;
    cout << "count: " << count << endl;
}