#include<iostream>
using namespace std;
class A{
    char sign = 'A';
    private:
        class B{
            private:
                char sign = 'B';
            public:
                char get_sign(){
                    return this -> sign;
                }
                class C{
                    void get_sign(){
                        cout << "c" << endl;
                    }
                };
        };
    public:
        char get_B(){
            B *b = new B();
            return b->get_sign();
        }
        char get_A(){
            return this -> sign;
        }        
};

int main(){
    A* a = new A();
    A &A = *a;
    cout << A.get_A() << endl;
    cout << A.get_B() << endl;
}