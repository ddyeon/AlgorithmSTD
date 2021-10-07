#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3] = {0, 0, 0};
    int now = -1;
    string tmp = "";
    for (int i = 0; i< dartResult.size(); i++){
        if ((dartResult[i]-'0'>= 0) && (dartResult[i]-'0'<=10)){
            tmp += dartResult[i];
        }
        else if (dartResult[i]=='S'){
            now += 1;
            score[now] = stoi(tmp);
            tmp = "";
        }
        else if (dartResult[i]=='D'){
            now += 1;
            score[now] = pow(stoi(tmp),2);
            tmp = "";
        }
        else if (dartResult[i]=='T'){
            now += 1;
            score[now] = pow(stoi(tmp),3);
            tmp = "";
        }
        else if (dartResult[i] == '*'){
            score[now] *= 2;
            if (now > 0){
                int n = now - 1;
                score[n] *= 2;
            }
        }
        else if (dartResult[i] == '#'){
            score[now] *= -1;
        }
        
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}
