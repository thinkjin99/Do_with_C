#include<iostream>
using namespace std;
class C{
    public:
        int* num = new int(100);
        ~C(){
            delete num;
            num = nullptr;
        }
};
int main(){
    C* c = new C();
    C*& c2 = c;
    int *d = nullptr;
    // cout << *(c->num) << endl;
    delete(c);
    cout << (c2->num) << endl;
    // cout << *d << endl;
}