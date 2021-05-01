#include<iostream>
using namespace std;
void PrintAB(int num, int size){
  if(num  == 0 && size == 0) return;
  PrintAB(num/2,size/2);
  if(num % 2 == 0) cout << "a";
  else cout << "b";
}

int main(){
    int num;
    cin >> num;
    for(int i = 0; i < pow(2,num); i++){
        PrintAB(i,pow(2,num - 1));
        cout << endl;
    }
}