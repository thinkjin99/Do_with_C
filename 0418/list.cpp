#include<iostream>
#include"list.h"
using namespace std;

void LinkedList::Append(int data){
    if(head == nullptr){
        head = new Node(data);
        tail = head;
    }
    else{
        tail->next = new Node(data);
        tail = tail->next;
    }
}

void LinkedList::Prepend(int data){
    Node* new_head = new Node(data);
    new_head->next = head;
    head = new_head;
}

void LinkedList::Print(){
    for(Node* i = head; i != nullptr; i = i->next){
        cout << i->data << " ";
    }
    cout << endl;
}

void LinkedList::PrintReverse(){

}

int LinkedList::Length(){
    int len = 0;
    for(Node* h = head; h!=nullptr; h = h->next) len++;
    return len;
}

