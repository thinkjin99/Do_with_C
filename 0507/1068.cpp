#include<iostream>
#include<vector>
using namespace std;

void removeNode(int num, vector< vector<int> > &childs, bool(&visited)[50]){
    while(childs[num].size() != 0){
        int back = childs[num].back();
        childs[num].pop_back();
        removeNode(back,childs,visited);
    }
    visited[num] = false;
    return;
}

int main(){
    int nodeNum;
    cin >> nodeNum;
    vector< vector<int> > childs (50,vector<int>(0,0));

    bool vistied[50] = {false};
    int parentIndex[50];
    for(int i = 0; i < nodeNum; i++){
        int parent; cin >> parent; // parent를 입력받고 
        if(parent != -1){
            parentIndex[i] = parent;
            childs[parent].push_back(i); // 자식 벡터의 각각의 parent의 위치에 n번째 노드를 추가
        }
        vistied[i] = true; // i번째를 추가하면 i 노드는 존재하는 것 이므로
    }

    int removeIndex;
    cin >> removeIndex;
    removeNode(removeIndex, childs, vistied);
    for (int i = 0; i < childs[parentIndex[removeIndex]].size(); i++){
        if(childs[parentIndex[removeIndex]][i] == removeIndex)
            childs[parentIndex[removeIndex]].erase(childs[parentIndex[removeIndex]].begin() + i);
    }
    
    int leaf = 0;
    for(int i = 0; i < 50; i++){
        if(vistied[i]){
            if(childs[i].size() == 0)
                leaf++;
        }
    }
    cout << leaf << endl;
}