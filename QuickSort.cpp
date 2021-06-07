#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Partition(vector<pair<int,int>> &v,int* arr,int left,int right){
    int pivot = arr[left];
    int low = left + 1;
    int high = right;
    while(low <= high){
        while (pivot <= arr[low] && low <= right) low++; //마지막 요소까지 확인을 해줘야 함
        while(pivot >= arr[high] && high >= left + 1) high--;  //값이 같을 때도 비교해줘야 무한루프를 벗어난다.
        if(low <= high) {
            swap(arr[low],arr[high]);
            swap(v[low],v[high]);
        }
    }
    swap(arr[left],arr[high]);
    swap(v[left],v[high]);
    return high;
}

void QuickSort(vector<pair<int,int>> &v,int* arr,int left,int right){
    if(left <= right){
        int pivot = Partition(v,arr,left,right);
        QuickSort(v,arr,left,pivot - 1);
        QuickSort(v,arr,pivot + 1, right);
    }
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    int* first = new int[n];
    int* second = new int[n];
    for(int i = 0; i < n; i++){
        int f,s;
        scanf("%d %d",&f,&s);
        v.push_back(make_pair(f,s));
        second[i] = v[i].second;
    }
    QuickSort(v,second,0,n - 1);
    for(int i = 0; i < n; i++) first[i] = v[i].first;
    QuickSort(v,first,0,n - 1);
    for(auto it = v.begin(); it != v.end(); it++){
        cout << (*it).first << "\t";
        cout << (*it).second << endl;
    }
}