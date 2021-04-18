#include<iostream>
using namespace std;
template<typename N>
class Chain{
    private:
        class Node{
            private:
                friend class Chain;
                N data;
                Node* link;
            public:
                Node(int data){
                    this->data = data;
                    link = nullptr;
                }
        };
        Node* head;
        Node* tail;

    public:
    Chain():head(nullptr),tail(nullptr){}
    void push(N data);
    void remove(N data);
    void push_front(N data);
    void print_list();
};

template<typename N>
void Chain<N>::push(N data){
    if(head == nullptr){
        head = new Node(data);
        tail = head;
    }
    else{
        tail->link = new Node(data);
        tail = tail->link;
    }
}

template<typename N>
void Chain<N>::print_list(){
    for(Node* i = head; i != nullptr; i = i->link){
        cout << i->data << endl;
    }
}

template<typename N>
void Chain<N>::remove(N data){
    for(Node* i = head; i != nullptr; i = i->link){
        Node* before;
        if(i->data != data){
            before = i;
            continue;
        }
        else{
            before->link = i->link;
            delete(i);
        }
    }
}

template<typename N>
void Chain<N>::push_front(N data){
    Node* new_head = new Node(data);
    new_head->link = head;
    head = new_head;
}

int main(){
    Chain<int> C;
    C.push(1);
    C.push(2);
    C.push(3);
    C.push(4);
    C.print_list();
    C.remove(4);
    C.print_list();
    C.push_front(5);
    C.print_list();
}