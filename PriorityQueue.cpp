#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<vector>
using namespace std;
void MinHeapify(vector<pair<int,int> > &heap, int i){
    while(i <= heap.size() / 2){
        int childIndex = i * 2;
        if(childIndex >= heap.size()) return;
        /*자식 인덱스의 + 1까지 비교하기에 바운드 오류가 발생할 것이라 생각했는데, 생각해보니 *2는 늘상
        왼쪽 자식을 가리키기에 자식 인덱스 +1이 바운드를 벗어 날 수 없다. */
        int k = (heap[childIndex].second < heap[childIndex + 1].second) ? childIndex : childIndex + 1;
        if(heap[i].second <= heap[k].second) return;
        swap(heap[i],heap[k]);
        i = k;
    }
}

void BuildMinheap(vector<pair<int,int> > &heap){
    for(int i = heap.size() / 2;  i >= 1; i--){
        MinHeapify(heap,i);
    } 
}

void HeapSort(vector<pair<int,int> > &heap){
    BuildMinheap(heap);
    for(int i = heap.size(); i >= 2; i--){
        swap(heap[1],heap[i]);
        heap.pop_back();    
        MinHeapify(heap,1);
    }
}

int main(){
    srand(time(NULL));
    vector<pair<int,int>> heap;
    heap.push_back(make_pair(0,0));
    int cnt = 11;
    for(int i = 1; i < cnt; i++){
        heap.push_back(make_pair(i,rand()%100));
    }
    HeapSort(heap);
    for(int i = 1; i < cnt; i++){
        cout << heap[i].first << " : " << heap[i].second << endl;
    }
}