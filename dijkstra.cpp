#include<iostream>
using namespace std;
const int n = 5;
void printArray(int graph[5][5]){
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << "\t" << graph[i][j];
            }
            cout << endl;
    }
}

int get_current(bool (&visited)[n],int(&weight)[n]){
    int current = 999;
    int index;
    for(int i = 0; i < n; i++){
        if(visited[i] == false && current > weight[i]){
            current  = weight[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int graph[n][n] = {};
    bool visited[n] = {false};
    int weight[n] = {0,2,5,999,3};
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++)
            graph[i][j] = 999;
    }
    graph[0][1] = 2;
    graph[0][2] = 5;
    graph[0][4] = 3;
    graph[1][3] = 4;
    graph[1][4] = 10;
    graph[2][3] = 6;
    graph[2][4] = 2;
    graph[4][2] = 1;
    graph[4][3] = 2;
    visited[0] = true;
    for(int i = 0; i < n - 1; i++){
        int current = get_current(visited,weight);
        cout << current << endl;
        visited[current] = true;
        for(int j = 0; j < n; j++){
            if(visited[j] != true && weight[current] + graph[current][j] < weight[j]){
                weight[j] = weight[current] + graph[current][j];
            }
        }
    }
    for(auto& i: weight) cout << i << "\t";
    // printArray(graph);
}
