#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double day;
    double night;
    int goal;
    cin >> day;
    cin >> night;
    cin >> goal;
    // int disatnce = day;
    // int count = 1;
    // while (distance < goal){
    //     distance -= night;
    //     distance += day;
    //     count++;
    // }
    double distance = (goal-day) / (day-night);
    int count = ceil(distance);
    cout << ++count << endl;
}