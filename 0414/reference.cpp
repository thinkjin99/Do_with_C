#include<iostream>
using namespace std;
class T{
    private:
        int num;

    public:
        T(int n):num(n){}
        void plus(){
            num++;
        }
        int get_num(){
            return num;
        }
    
};
T* return_t(T *t){
    t->plus();
    return t;
}
int main(){
    T* t = new T(5);
    cout << t->get_num() << endl;
    cout << return_t(t)->get_num() << endl;
    cout << (*t).get_num() << endl;
}