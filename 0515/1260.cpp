#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> vertaxArray[1001];
bool visit[1001] = {false};
void dfs(int vertaxIndex){
    if(visit[vertaxIndex] == true) return;
    vector<int> &vertax = vertaxArray[vertaxIndex];
    cout << vertaxIndex << "   ";
    visit[vertaxIndex] = true;
    if(vertax.empty()) return;
    for(int i = 0; i != vertax.size(); i++){
        dfs(vertax[i]);
    }
    cout << endl;
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
    
    for(int i = 0; i < 1001; i++) visit[i] = 0;
    dfs(startPoint);

}

// void printVector(){
//     for(int i = 0; i < 1001; i++){
//             for(auto j= vertaxArray[i].begin(); j != vertaxArray[i].end(); ++j){
//                 cout << i << " j : " << *j;
//             }
//         }
// }