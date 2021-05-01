#include<iostream>
using namespace std;
class Temp{
    private:
        string content;
    public:
        void set_content(string s){
            content += s;
        }
        string get_content()const{
            return content;
        }
};
const Temp operator *(string front, int num){
    Temp t;
    for(int i = 0; i < num; i++)
        t.set_content(front);
    return t;
}

int main(){
    string a = "123";
    cout << "adress : " << (a*4).get_content() << endl;

}