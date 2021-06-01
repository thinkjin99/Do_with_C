#include<iostream>
#include<algorithm>
using namespace std;
void MergeTwoArea(int arr[], int left, int mid, int right){
    int fidx = left;
    int ridx = mid + 1;
    int *sortArr = new int[right + 1];
    int sidx = left; //정렬된 원소의 수
    while(fidx <= mid && ridx <= right){
        if(arr[fidx] < arr[ridx]){
            sortArr[sidx++] = arr[fidx++]; //오름차순 정렬이므로
        }
        else{
            sortArr[sidx++] = arr[ridx++];
        }
    }
    //배열에 남아있는 요소들 마저 입력
    if(ridx > right){
        while(fidx <= mid){
            sortArr[sidx++] = arr[fidx++];
        }
    }
    else{
      while(ridx <= right){
            sortArr[sidx++] = arr[ridx++];
        }
    }
    for(int i = left; i <= right; i++){
        arr[i] = sortArr[i];
    }
    free(sortArr);
}

void MergeSort(int arr[], int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid + 1,right);
        MergeTwoArea(arr,left,mid,right);
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d",&num);
        arr[i] = num;
    }
    MergeSort(arr,0,n - 1);
    cout << arr[k - 1] << '\n';
}