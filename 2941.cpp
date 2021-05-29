#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    string s;
    map<char,string> m;
    vector <char> point;
    m['c'] = "-=";
    m['d'] = "z-";
    m['l'] = "j";
    m['n'] = "j";
    m['s'] = "=";
    m['z'] = "=";
    int cnt = 0;
    cin >> s;
    for(int i = 0; i < s.length() - 1; i++){
        int loc = i;
        vector <char> letters;
        bool is_complete = false;
        while (m.find(s[loc]) != m.end() && m[s[loc]].find(s[loc + 1]) != string::npos){
            letters.push_back(s[loc]);
            loc++;
            if(s[loc - 1] == 'd' && s[loc] == 'z'){
                is_complete = false;
                continue;
            }
            i++;
            is_complete = true;
            letters.push_back(s[loc]);
        }
        if(is_complete){
            cnt += letters.size() -1;
        }
    }
    cout << s.length() - cnt << endl;
}




    // for(auto it = point.begin(); it != point.end(); it++){
    //     cout << *it << endl;
    // }
    // c++ string 비교는 == 이 오버로딩 돼 comapare()와 같이 동작한다.
    // for(int i = 0; i < startPoint.size(); i++){
    //     bool is_d = false;
    //     int loc = startPoint[i] + 1;
    //     for(int j = loc; j < loc + 2; j++){
    //         char startLetter = s.at(loc - 1);
    //         if(j == s.length() - 1) continue;
    //         for(int k = 0; k < endPatterns.length(); k++){
    //             if(endPatterns[k] == s[j])
    //         }

    //     }

    // }



    