#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int day = 2;
    int night = 1;
    int goal = 5;
    int distance = day;
    int count = 1;
    while (distance < goal) {
        distance = (count + 1) * day  - count * night;
        // 노트 참조
        count++;
    }
    cout << count << endl;
}