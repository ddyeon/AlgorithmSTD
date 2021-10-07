// 위클리챌린지 _ 2주차 상호평가
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    vector<vector<int>> my_score;
    vector <double> avg_score;
    for (int i = 0; i < scores.size(); i++){
        vector <int> v;
        for (int j = 0; j < scores[i].size(); j++){
            v.push_back(scores[j][i]);
        }
        my_score.push_back(v);
    }
    
    for (int i = 0; i < my_score.size(); i++){
        int my_myscore = my_score[i][i];
        bool not_max = false;
        bool not_min = false;
        for (int j = 0; j < my_score[i].size(); j++){
            if (i != j){
                if (my_score[i][j] >= my_myscore){ //유일한 최고점 아님
                    not_max = true;
                }
                if (my_score[i][j] <= my_myscore){ //유일한 최저점 아님
                    not_min = true;
                }
            }
        }
        if ((not_min == false) or (not_max == false)){
            my_score[i].erase(my_score[i].begin() + i); //제외
        }
        double tmp = 0;
        for (int k = 0; k < my_score[i].size(); k++){
            tmp += my_score[i][k];
        }
        tmp /= double(my_score[i].size());
        avg_score.push_back(tmp);
    }
    for (int i = 0; i < avg_score.size(); i++){
        if (avg_score[i] >= 90){
            answer += 'A';
        }
        else if (avg_score[i] >= 80){
            answer += 'B';
        }
        else if (avg_score[i] >= 70){
            answer += 'C';
        }
        else if (avg_score[i]>= 50){
            answer += 'D';
        }
        else{
            answer += 'F';
        }
    }
    return answer;
}
