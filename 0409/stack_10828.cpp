#include <iostream>
using namespace std;
template<typename S>
class Stack{
    private:
        S array[10000];
        int head;
        int size;
        void Push();
        void Pop();

        void Size(){
            cout << size << endl;
        } 
        
        void Top(){
            if (size == 0){
                cout << -1 << endl;
                return;
            }
            cout << array[head] << endl;
        }

        void Empty(){
            if(size == 0){
                cout << 1 << endl;
                return;
            }
            cout << 0 << endl;
        }

    public: 
        Stack():head(-1),size(0){}
        void Command(string cmd){
            if (cmd == "push")this->Push();
            else if (cmd =="pop")this->Pop();
            else if (cmd == "empty")this->Empty();
            else if (cmd == "size")this->Size();
            else if (cmd == "top")this->Top();
            }
};

template <typename S>
void Stack<S>::Push(){
    S data;
    cin >> data;
    array[++head] = data;
    size++;
}

template <typename S>
void Stack<S>::Pop(){
    if (size == 0){
        cout << -1 << endl;
        return;
    }
    cout << array[head] << endl;
    if(head >= 0){head--;} 
    if(size >= 0){size--;}
    return;
}

int main(){
    Stack <int> S;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        S.Command(command);
    }
}