#include<iostream>
#include<string>
#include"graph.h"
using namespace std;
int Graph::GetCurrent(bool* visited, int* weight){
    int current = 999;
    int index;
    for(int i = 0; i < size; i++){
        if(visited[i] == false && current >= weight[i]){
            //가중치가 전부 같거나 간선이 존재하지 않는 정점을 생각해주자.
            current  = weight[i];
            index = i;
        }
    } //index 초기화 안됨
    return index;
}

void Graph::GetshortPath(int vertax){
    for(int i = 0; i < size; i++){
        weight[i] = graph[vertax][i]; // 시작 정점의 인접 간선 초기화
        passedVertax[i].push_back(0); // 경로 연산을 위한 초기화
    }
    visited[vertax] = true;
    for(int i = 0; i < size - 2; i++){ //n-1번 반복하면 된다.
        int current = GetCurrent(visited,weight);
        // cout << vertax << "   " << current << endl;
        visited[current] = true;
        for(int j = 0; j < size; j++){
            if(visited[j] != true && weight[current] + graph[current][j] < weight[j]){
                weight[j] = weight[current] + graph[current][j];
                passedVertax[j].push_back(current);
            }
        }
    }
}

void Graph:: PrintShortestPathWeight(int start){
    GetshortPath(start);
    for(int i = 0; i < size; i++){
        cout << weight[i] << endl;
    }
    for(int i = 0; i < size; i++) {
        visited[i] = false;    
    }
}

void Graph::SetValue(int size){
    this->weight = new int[size];
    this->visited = new bool[size];
    this->graph = new vector<int>[size];
    this->passedVertax = new vector<int>[size];
}

void Graph::LoadMatrix(string& filename){
    ifstream infile(filename);
    string line;
    getline(infile,line); //getline은 istream을 반환하고 line에 저장해줌
    this->size = stoi(line);
    this->SetValue(size); //그래프의 필요 요소들을 동적으로 할당

    int index = 0;
    while(getline(infile,line,'\n')){
        stringstream ss(line);
        string temp;
        while (getline(ss,temp,' ')){
            graph[index/size].push_back(stoi(temp));
            index++;
        }
    }
}

void Graph::PrintMatrix(){
      for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }
}
int Graph::GetSize(){
    return size;
}
void Graph::PrintShortestPath(int vertax){
    GetshortPath(vertax);
    for(int i = 1; i < size; i++){
        vector<int> path = {0};
        int index = i;
        while(passedVertax[index].back() != 0){
            index = passedVertax[index].back();
            path.push_back(index);
        }
        path.push_back(i);
        cout << 0 << " ";
        for(int j = path.size() - 2; j > 0; j--) cout << path[j] << " ";
        cout << i << endl;
    }
}

// int main(void) {
//     Graph g;
    
//     string filename = "input.txt";
//     // getline(cin, filename);
    
//     g.LoadMatrix(filename);
//     g.PrintShortestPath(0);

//     return 0;
// }