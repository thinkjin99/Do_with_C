#include<iostream>
#include<vector>
using namespace std;
const int maxCityNum = 101;
const int INF = 987654321;
void Floyd(long long (&graph)[maxCityNum][maxCityNum], int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                } 
            }
        }
    }
}

int main(){
int n,m;
    cin >> n >> m;
    long long graph[maxCityNum][maxCityNum]; // 간선 정보 표시
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) {
                graph[i][j] = 0;
                continue;
            }
            graph[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int start,end,cost;
        scanf("%d %d %d",&start,&end,&cost);
        if(graph[start][end] < cost) continue;
        graph[start][end] = cost;
    }
    Floyd(graph,n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == INF) graph[i][j] = 0;
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }  
}