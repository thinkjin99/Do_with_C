#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxCityNum = 501;
const int INF = 987654321;
void printWeight(long long* w, int n){
    for(int i = 2;  i <= n; i++){
        if(w[i] == INF) w[i] = -1;
        cout << w[i] << endl;
    } 
}
bool BellFord(vector<pair<int,int>> (&graph)[maxCityNum], long long weight[], int n){
    for(int i = 1; i <= n; i++){ //정점의 개수 -1개 까지 반복
        for(int j = 1; j <= n; j++){ //도시의 수만큼 반복
            if(weight[j] == INF) continue;
            for(int k = 0; k < graph[j].size(); k++){
                int next = graph[j][k].first;
                int nDistance = graph[j][k].second;
                if(weight[j] + nDistance < weight[next]){
                    if(i == n){cout << -1 << endl; return true;}
                    weight[next] = weight[j] + nDistance;
                }
            }
        }
    }
    return false;
}

int main(){
    int n,m; // 도시의 수, 간선의 수 
    int startPoint,destination;
    cin >> n >> m;
    long long* weight = new long long[n + 1];
    weight[1] = 0; //시작 위치의 가중치는 0으로 처리
    for(int i = 2; i <= n; i++) weight[i] = INF; //0번 째는 참조할 일이 없다.
    vector<pair<int,int>> graph[maxCityNum]; // 간선 정보 표시 도시의 최대 수 500

    for(int i = 0; i < m; i++){
        int start,end,cost;
        scanf("%d %d %d",&start,&end,&cost);
        graph[start].push_back(make_pair(end,cost));
    }

    if(!BellFord(graph,weight,n)) printWeight(weight,n);
}
