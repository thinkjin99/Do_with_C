#include<iostream>
using namespace std;
class Rectangle{
    private:
        int row;
        int col;
    public:
        Rectangle(int row,int col):row(row),col(col){}
        int get_row();
        int get_col(){
            return col;
        }
        void operator ==(Rectangle& s);
        /* 왜 멤버함수로 연산자 오버로딩을 진행하면 매개변수를 1개만 받을까.
           고것은 멤버 함수인 이상 기본적으로 this를 인자로 받기 때문이다.
           연산자의 특성상 두개의 파라미터만 수용가능 한데 this가 한 자리를 차지하니
           한자리 밖에 들어가지 못하는 것이다. 따라서 파라미터를 2개 사용해야하는 연산자
           오버로딩을 진행해야 하는 경우 멤버함수로 정의하면 안된다. 정석적으로는 클래스 내부의
           요소를 사용하는 경우가 많으니 friend를 통해 접근권을 얻고 외부에서 따로 정의 한다. 
    */
        friend ostream& operator << (ostream& os,Rectangle& s);
};

void Rectangle::operator == (Rectangle& s){
    if ((this->row == s.row) && (this->col == s.col)){
        cout << "same Rect" << endl;
        
    }
    else{
        cout << "Different Rect" << endl;
    }
}
ostream& operator << (ostream& os, Rectangle& r){
    os << r.col << endl;
    os << r.row << endl;
    return os;
}

int Rectangle:: get_row(){
    return this->col;
}

int main(){
    Rectangle* r1 = new Rectangle(5,4);
    Rectangle* r2 = new Rectangle(5,4);
    //포인터로 인스턴스 생성시 레퍼런스에 바로 할당 할 수 없다.
    //r1은 클래스를 가리키는 포인터이지 Rectanlge 클래스 그 자체가 아니다.
    //reference를 통해 할당하고 싶으면 r1이 가리키는 곳을 할당해줘야한다.
    Rectangle& r3 = *r1;
    Rectangle& r4 = *r2;

    r3==r4;
    cout << r3 << r4;
    //포인터로 넘김과 레퍼런스로 전달의 차이
}