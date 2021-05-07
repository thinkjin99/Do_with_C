#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    int data;
    vector<Node> node;
    Node* parent;
    public:
        Node(Node* parent, int data):parent(parent),data(data){}
};

class Tree{
    public:
        Node* head;
        int countLeaf();
        void pushNode(vector<int>& v);
};

int main(){
    int nodeNum;
    cin >> nodeNum;
    vector< vector<int> > childs (50,vector<int>(0,0));
    Tree* t = new Tree();
    int head; cin >> head;
    t->head = new Node(nullptr,head);
    for(int i = 1; i < nodeNum; i++){
        int num; cin >> num;
        childs[num].push_back(i);
    }

    for(int i = 0; i != childs.size(); i++){
        for(int j = 0; j != childs[i].size(); j++){
            cout << childs[i][j] << "  ";
        }
        cout << endl;
    }
}