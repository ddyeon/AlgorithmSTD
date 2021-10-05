#include <string>
#include <vector>
#include <iostream>
using namespace std;
//왜 11번만 통과를 못하는지 모르겠다..
char checkScore(double sc)
{
    if(sc >= 90)
        return 'A';
    else if(sc >=80 && sc < 90)
        return 'B';
    else if(sc >= 70 && sc < 80)
        return 'C';
    else if(sc >= 50 && sc < 70)
        return 'D';
    else
        return 'F';
}
//평균구하기
string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i = 0; i < scores.size(); i++)
    {
        int num = scores[i][i];
        int sum = 0;
        int max_sc = 0;
        int min_sc = 100;
        bool flag = true;
        for(int j = 0; j < scores.size(); j++)
        {
            if (i != j && scores[j][i] == num) flag = false;
            sum += scores[j][i];
            if(scores[j][i] >= max_sc) max_sc = scores[i][j];
            if(scores[j][i] <= min_sc) min_sc = scores[j][i];
        }
        
        double avg = 0;
        if( (max_sc == num && flag) || (min_sc == num && flag))
        {
            sum -= num;
            avg = (double)sum / (double)(scores.size()-1);
        }
        else
            avg = (double)sum /(double)scores.size();
        
     
        answer.push_back(checkScore(avg));
    }
    
    return answer;
}
