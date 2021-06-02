#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void printWeight(int w[],int n){
    for(int i = 1; i <= n; i++) cout << w[i] << "\t";
    cout << endl;
}

void printheap(vector<pair<int,int> > &heap){
    for(auto it = heap.begin(); it!=heap.end(); it++) cout << (*it).first << "\t";
    cout << endl;
}

void MinHeapify(vector<pair<int,int> > &heap, int i){
    while(i <= heap.size() / 2){
        int childIndex = i * 2;
        if(childIndex >= heap.size()) return;
        int k = (heap[childIndex].second < heap[childIndex + 1].second) ? childIndex : childIndex + 1;
        //자식 인덱스 +1 의 경우 heap.size()와 일치하는 경우가 있어 bound over가 일어나는 경우가 발생한다.
        if(childIndex + 1 == heap.size()){
            k = childIndex;
        }
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
    for(int i = heap.size() - 1; i > 0; i--){
        cout << heap[1].second << endl;
        swap(heap[1],heap[i]);
        heap.pop_back();    
        MinHeapify(heap,1);
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    bool visited[1000] = {false};
    vector<pair<int,int>> prioQueue;
    vector<pair<int,int>> graph[n + 1];
    for(int i = 0; i < m; i++){
        int start,end,cost;
        scanf("%d %d %d",&start,&end,&cost);
        graph[start].push_back(make_pair(end,cost));

    // graph[1].push_back(make_pair(2,2));
    // graph[1].push_back(make_pair(3,3));
    // graph[1].push_back(make_pair(4,1));
    // graph[1].push_back(make_pair(5,10));

    // graph[2].push_back(make_pair(4,2));

    // graph[3].push_back(make_pair(4,1));
    // graph[3].push_back(make_pair(5,1));

    // graph[4].push_back(make_pair(5,3));
    // }

    int startPoint,destination;
    std:: cin >> startPoint >> destination;

    int* weight = new int[n + 1];
    for(int i = 0; i < n + 1; i++) weight[i] = 1000001;
    weight[startPoint] = 0;

    int sortedNums = 0;
    prioQueue.push_back(make_pair(startPoint,0));
    int current = startPoint;
    int distance = 0;

    while(sortedNums != n){
        visited[current] = true;
        for(int j = 0; j < graph[current].size(); j++){
            int next = graph[current][j].first;
            int nextD = graph[current][j].second;
            if(visited[next] != true && weight[current] + nextD < weight[next]){
                    weight[next] = weight[current] + nextD;
                    prioQueue.push_back(make_pair(next, nextD));
            }
        }
        printheap(prioQueue);
        BuildMinheap(prioQueue);
        printWeight(weight,n);
        current = prioQueue[1].first;
        distance = prioQueue[1].second;
        swap(prioQueue[1],prioQueue[prioQueue.size() - 1]);
        prioQueue.pop_back();
        MinHeapify(prioQueue,1);
        sortedNums++;
    }
    // printArray(graph);
}
