//
//  main.cpp
//  soomin_방문 길이
//
//  Created by 김수민 on 2021/07/22.
//
#include <iostream>
#include <string>
#include <map>
#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    map <string, int> m;
    int nowx = 0;
    int nowy = 0;
    for (int i = 0; i< dirs.length(); i++){
        string s1 = "";
        string s2 = "";
        int beforex = nowx;
        int beforey = nowy;
        if (dirs[i] == 'U'){
            if (nowy + 1 <= 5){
                nowy += 1;
            }
        }
        else if (dirs[i] == 'D'){
            if (nowy - 1 >= -5){
                nowy -= 1;
            }
        }
        else if (dirs[i] == 'R'){
            if (nowx + 1 <= 5){
                nowx += 1;
            }
        }
        else{
            if (nowx - 1 >= -5){
                nowx -= 1;
            }
        }
        s1+=to_string(beforex);
        s1+=to_string(beforey);
        s1+=to_string(nowx);
        s1+=to_string(nowy);
        m[s1] += 1;
        s2+=to_string(nowx);
        s2+=to_string(nowy);
        s2+=to_string(beforex);
        s2+=to_string(beforey);
        m[s2] += 1;
        if ((m[s1] == 1)&&(m[s2] == 1)){
            answer += 1;
        }
    }
    return answer;
}

int main(){
    cout<< solution("ULURRDLLU")<< endl;
}
