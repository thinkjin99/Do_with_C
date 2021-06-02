#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printheap(vector<pair<int,int> > &heap){
    for(auto it = heap.begin(); it!=heap.end(); it++) cout << (*it).first << "\t";
    cout << endl;
}
void printWeight(int* w, int n){
    for(int i = 1;  i <= n; i++) cout << w[i] << "\t";
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

int main(){
    int n,m;
    int startPoint,destination;
    cin >> n >> m;
    int* weight = new int[n + 1];
    for(int i = 0; i < n + 1; i++) weight[i] = 987654321;
    // bool visited[1000] = {false};
    vector<pair<int,int>> prioQueue; //우선 순위 큐 (가중치 저장)
    vector<pair<int,int>> graph[n + 1]; // 간선 정보 표시
    for(int i = 0; i < m; i++){
        int start,end,cost;
        scanf("%d %d %d",&start,&end,&cost);
        graph[start].push_back(make_pair(end,cost));
    }

    scanf("%d %d",&startPoint,&destination);

    //int sortedNums = 0; //현재까지 찾은 최단 거리의 수 
    weight[startPoint] = 0; //시작 위치의 가중치는 0으로 처리

    prioQueue.push_back(make_pair(startPoint,0)); // 시작점의 간선 정보
    int current = startPoint;
    bool isEmpty = false;
    while(!isEmpty){ //모든 정점의 최단거리를 구할 때 까지.
        // visited[current] = true;
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int nextD = graph[current][i].second;
            if(weight[current] + nextD < weight[next]){
                    weight[next] = weight[current] + nextD;
                    prioQueue.push_back(make_pair(next, nextD));
            }
        }
        if(prioQueue.size() == 1) isEmpty = true;
        BuildMinheap(prioQueue); //최소힙으로 구성
        current = prioQueue[1].first; //최소 값 추출
        swap(prioQueue[1],prioQueue[prioQueue.size() - 1]);
        prioQueue.pop_back(); //최소 값을 제거
        MinHeapify(prioQueue,1); //다시금 최소 힙으로 생성
        // printWeight(weight,n);
        // if(current == startPoint) isEmpty = true;
       // sortedNums++; //최단거리를 알고있는 정점의 수 증가
    }

    cout << weight[destination] << endl;
}
