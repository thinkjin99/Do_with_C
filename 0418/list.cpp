#include <iostream>
#include <string>
#include <sstream>
#include "list.h"
using namespace std;

void LinkedList::Append(int data){
        tail->next = new Node(data);
        tail->next->prev = tail;
        tail = tail->next;
}

void LinkedList::Prepend(int data){
    Node* new_head = new Node(data);
    new_head->next = head->next;
    new_head->prev = head;
    head->next = new_head;
    if(tail == head) tail = new_head; // 모든 요소를 앞에 추가 할 경우 
    if(new_head->next == nullptr) return; //다음이 널이면 이전을 신경 쓸 필요가 없다.
    new_head->next->prev = new_head;
}

void LinkedList::Print(){
    for(Node* i = head->next; i != nullptr; i = i->next){
        cout << i->data << " ";
    }
    cout << endl;
}

void LinkedList::PrintReverse(){
    for(Node *p = tail; p != head; p = p->prev) cout << p->data << " ";
    cout << endl;
}

int LinkedList::Length(){
    int len = 0;
    for(Node* h = head->next; h!=nullptr; h = h->next) len++;
    return len;
}


   