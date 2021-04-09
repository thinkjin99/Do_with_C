#include <iostream>
using namespace std;
template<typename S>
class Stack{
    private:
        int head;
        int size;
        S array[10000];
        void Push();
        void Empty();
        void Pop();
        void Size(); 
        void Top();

    public:
       void Print_All(){
            for(int i = 0; i <= head; i++){
                cout << array[i] << endl;
            }
        }
        Stack():head(-1),size(0){}
        void Command(string cmd){
            if (!strcmp(cmd.c_str(),"push")) this->Push();
            // else if (strcmp(cmd.c_str(),"pop"))
            //     this->Pop();
            // else if (strcmp(cmd.c_str(),"empty"))
            //     this->Empty();
            // else if (strcmp(cmd.c_str(),"size"))
            //     this->Size();
            // else if (strcmp(cmd.c_str(),"top"))
            //     this->Top();
            else
                cout << "Wrong input" << endl;
            }
};

template <typename S>
void Stack<S>::Push(){
    S data;
    cout << "Input push Data" << ": ";
    cin >> data;
    array[++head] = data;
    size++;
}


int main(){
    Stack <int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        s.Command(command);
    }
      s.Print_All();
}