#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool oper(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

string grade(int score){
    if(score>=90)return "A";
    else if(score >=80) return "B";
    else if(score >=70) return "C";
    else if(score >=50) return "D";
    else return "F";
}
vector<pair<int,int>> v[11];

string solution(vector<vector<int>> scores) {
    string answer = "";
    int sum = 0;
    string tmp ="";
    for(int i=0; i<scores.size(); i++){
        sum=0;
        tmp="";
        
        for(int j=0; j<scores.size(); j++){
            v[i].push_back({j, scores[j][i]});            
            sum +=scores[j][i];
        }
        sort(v[i].begin(), v[i].end(), oper);
        if((v[i][0].second != v[i][1].second) && (v[i][0].first==i)){

            sum -= v[i][0].second;
            tmp = grade(sum / (scores.size()-1) );
        }
        else if((v[i][scores.size()-1].second != v[i][scores.size()-2].second) &&
                (v[i][scores.size()-1].first == i)){
                       
            sum -= v[i][scores.size()-1].second;
            tmp = grade(sum/(scores.size()-1));
        }
        else{
            tmp = grade(sum/scores.size());
        }
        answer += tmp;
    
    }

    return answer;
}
