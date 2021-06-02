#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

void printheap(vector<int> &heap){
    for(auto it = heap.begin(); it!=heap.end(); it++) cout << *it << "\t";
    cout << endl;
}

void MinHeapify(vector<int> &heap, const int root, int n){
    int e = heap[root];
    int i = 2 * root;
    for(; i <= n; i++){
        if(i < n && heap[i] < heap[i+1]) i++;
        if(e >= heap[i]) break;
        heap[i/2] = heap[i];
    }
    heap[i/2] = e;
}

void BuildMinheap(vector<int> &heap, int cnt){
    for(int i = heap.size() / 2;  i >= 1; i--){
        MinHeapify(heap,i,cnt);
    } 
}

// void HeapSort(vector<int> &heap){
//     BuildMinheap(heap);
// }

int main(){
    time(NULL);
    vector<int> heap;
    heap.push_back(0);
    int cnt = 10;
    for(int i = 1; i <= cnt; i++){
        heap.push_back(i);
    }
    BuildMinheap(heap,cnt);
    printheap(heap);
}