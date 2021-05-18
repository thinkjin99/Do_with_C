#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
vector<int> vertaxArray[1001];
bool visit[1001] = {false};
void dfs(int vertaxIndex){
    if(visit[vertaxIndex] == true) return;
    vector<int> &vertax = vertaxArray[vertaxIndex];
    cout << vertaxIndex << " ";
    visit[vertaxIndex] = true;
    if(vertax.empty()) return;
    for(int i = 0; i != vertax.size(); i++){
        dfs(vertax[i]);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start); // 처음 시작점을 큐에 추가
    while(!q.empty()){
        int front = q.front();
        if(visit[front] == false){
            cout << front << " ";
            visit[front] = true;
            for(int i = 0; i < vertaxArray[front].size(); i++){
                q.push(vertaxArray[front][i]);
            }
        }
        q.pop();
    }
}

int main(){
    int vertaxNum,vertaxIndexNum,startPoint;
    cin >> vertaxNum >> vertaxIndexNum >> startPoint;
    for(int i = 0; i < vertaxIndexNum; i++){
        int vertax,vertaxIndex; cin >> vertax >> vertaxIndex ;
        vertaxArray[vertax].push_back(vertaxIndex);
        vertaxArray[vertaxIndex].push_back(vertax); //양방향 그래프
    }

    for(int i = 1; vertaxArray[i].size() != 0; i++){
        sort(vertaxArray[i].begin(),vertaxArray[i].end());
    }
    dfs(startPoint);
    for(int i = 0; i < 1001; i++) visit[i] = 0;
    cout << endl;
    bfs(startPoint);
    cout << endl;
}

// void printVector(){
//     for(int i = 0; i < 1001; i++){
//             for(auto j= vertaxArray[i].begin(); j != vertaxArray[i].end(); ++j){
//                 cout << i << " j : " << *j;
//             }
//         }
// }