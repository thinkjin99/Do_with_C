#include<iostream>
using namespace std;
template<typename Q>
class Queue{
    private:
        Q array[10000];
        int front;
        int back;
        int size;
        void Push();
        int Pop();
        int get_Size(){return size;}
        bool Is_Empty(){return front == back;}
        int Front(){
            if(Is_Empty()){
                return -1;
            }
            return array[front];
        }
        int Back(){
            if(Is_Empty()){
                return -1;
            }
            return array[back - 1];
        }

    public:
        Queue();
        void Command(string cmd){
            if (cmd == "push")this->Push(); 
            else if (cmd =="pop")cout << this->Pop() << endl;
            else if (cmd == "empty")cout << this->Is_Empty() << endl;
            else if (cmd == "size")cout << this->get_Size() << endl;
            else if (cmd == "front")cout << this->Front() << endl;
            else if (cmd == "back")cout << this->Back() << endl;
            else cout << "Wrong Input" << endl;
        }

};
template<typename Q>
Queue<Q>::Queue():front(0),back(0),size(0){}

template<typename Q>
void Queue<Q>::Push(){
    Q data;
    cin >> data;
    array[back++] = data;
    size++;
}
template<typename Q>
int Queue<Q>::Pop(){
    if(Is_Empty()){
       return -1;
    }
    size--;
    return array[front++];
}
int main(){
    Queue <int> Q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        Q.Command(command);
    }
}