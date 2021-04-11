#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i++){      
          dq.push_back(i);
    }
    for(int i = 0; i < m; i++){
        int num;
        int index;
        cin >> num;
        for(int j = 0; j < dq.size(); j++){
            if(dq[j] == num){
                index = j;
                break;
            }   
        }

        if(index <= (dq.size() - 1) / 2){
            while (dq.front() != num){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }

        else{
            while (dq.front() != num){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }
    cout << cnt << endl;
}
