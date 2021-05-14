#include<iostream>
using namespace std;
class Tree; // class forward declaration
class Node{
    private:
        friend Tree;
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int data):data(data){}
};

class Tree{
    public:
        Node* head = nullptr;
        void Push(int data);
        void PostOrder(Node* loc);
        void PreOreder(Node* loc);
        Tree(int head_data){
            head = new Node(head_data);
        }
};

void Tree::PostOrder(Node* loc){
    if(loc == nullptr) return;
    PostOrder(loc->left);
    PostOrder(loc->right);
    printf("%d\n",loc->data);
}

void Tree::Push(int data){
    Node* loc = this->head;
    while (true){
        if(loc -> data > data){
            if(loc -> left == nullptr){
               loc->left = new Node(data);
               loc = loc->left;
               break;
           }
           else loc = loc->left;
       }
       else{
           if(loc -> right == nullptr) {
               loc->right = new Node(data);
               loc = loc -> right;
               break;
           }
           else loc = loc->right;
           }
   }
}


int main(){
    int head_data; 
    scanf("%d",&head_data);
    Tree* T = new Tree(head_data);
    int data; 
    while(scanf("%d",&data) == 1){
        T->Push(data);
    }
    T->PostOrder(T->head);
}