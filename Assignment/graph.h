#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
class Graph{
    private:
        int size;
        vector<int>* graph;
        vector<int>* passedVertax;
        int* weight;
        bool* visited;
        int GetCurrent(bool* visited,int* weight);
        void SetValue(int size);
      
    public:
        void LoadMatrix(std::string& filename);
        void PrintMatrix();
        void GetshortPath(int vertax);
        void PrintShortestPathWeight(int vertax); 
        void PrintShortestPath(int vertax);
        int GetSize();
    };