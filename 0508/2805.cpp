#include<iostream>
#include<vector>
using namespace std;
int result = 0;
int BinarySearch(int start, int end , int& neededWood , vector<int> &arr){
    if(start <= end){
        long long cuttingPoint = (start + end) / 2;
        // cout << cuttingPoint << endl;
        long long sliceWood = 0;
        vector<int>::iterator v;
        for(v = arr.begin(); v != arr.end(); v++){
            if((*v - cuttingPoint) > 0) sliceWood += (*v - cuttingPoint);
        }
        if(sliceWood < neededWood) 
            return BinarySearch(start, cuttingPoint - 1, neededWood, arr);

        else if(sliceWood >= neededWood)
            result = cuttingPoint > result ? cuttingPoint: result;
            // 우리가 원하는 만큼의 나무가 정확히 안떨어져 나올 가능성이 존재하기 때문에 최대치를 계속 갱신해줘야 한다.
            // 최대치를 구하는 것이 핵심이다.
            return BinarySearch(cuttingPoint + 1, end, neededWood, arr);
    }
    return result;
}

int main(){
    int woodNum;
    int neededWood;
    cin >> woodNum >> neededWood;
    vector<int> arr;
    int end = 0;
    for(int i = 0; i < woodNum; i++){
        int height; cin >> height;
        if(height > end) end = height;
        arr.push_back(height);
    }
    cout << BinarySearch(0,end,neededWood,arr) << endl;
}