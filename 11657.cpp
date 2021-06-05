#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxCityNum = 501;
const int INF = 987654321;
void printWeight(int* w, int n){
    for(int i = 2;  i <= n; i++){
        if(w[i] == INF) w[i] = -1;
        cout << w[i] << endl;
    } 
}
bool BellFord(vector<pair<int,int>> (&graph)[maxCityNum], int weight[],int n){
    for(int i = 1; i < n; i++){ //입력된 도시의 수 만큼 반복
        for(int j = 0; j < graph[i].size(); j++){
            int next = graph[i][j].first;
            int nDistance = graph[i][j].second;
            if(weight[i] + nDistance < weight[next]){
                if(checkCycle){
                    cout << -1 << endl;
                    return true;
                }
                weight[next] = weight[i] + nDistance;
            }
        }
    }
    return false;
}

int main(){
    int n,m; // 도시의 수, 간선의 수 
    int startPoint,destination;
    cin >> n >> m;
    int* weight = new int[maxCityNum];
    weight[1] = 0; //시작 위치의 가중치는 0으로 처리
    for(int i = 2; i <= n; i++) weight[i] = INF; //0번 째는 참조할 일이 없다.
    vector<pair<int,int>> graph[maxCityNum]; // 간선 정보 표시 도시의 최대 수 500
    bool checkCycle = false;

    for(int i = 0; i < m; i++){
        int start,end,cost;
        scanf("%d %d %d",&start,&end,&cost);
        graph[start].push_back(make_pair(end,cost));
    }

    BellFord(graph,weight,checkCycle);    
    checkCycle = true;
    if(BellFord(graph,weight,checkCycle) != true){
        printWeight(weight,n);
    }
}
