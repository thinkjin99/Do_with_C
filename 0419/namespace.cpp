#include<iostream>
using namespace std;
namespace Do{
    void do_something(){
        cout << "do something" << endl;
    }
}
namespace Any{
    void do_something(){
        cout << "do anything" << endl;
    }
}
namespace Foo { 
	namespace Goo { 
			const int g_x = 5; 
			//Foo::Goo::g_x
	} 
}
namespace Boo = Foo::Goo;
using namespace Boo; 
//네임스페이스에 별칭을 지정해 간단히 표현 할 수 있다.
int main(){
    Do::do_something();
		//:: 범위 지정자를 통해 범위 지정
    Any::do_something();
		cout << g_x << endl;
}