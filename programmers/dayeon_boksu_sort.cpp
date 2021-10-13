#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct { 
    int num; 
    int weight; 
    double winRate; 
    int winWeight; 
} Boksu;

bool cmp(Boksu a, Boksu b)
{
    if(a.winRate > b.winRate)
        return true;
    if(a.winRate == b.winRate)
    {
        if(a.winWeight > b.winWeight) //자기보다 큰 무게 이긴사람
            return true;
        if(a.winWeight == b.winWeight)
        {
            if(a.weight > b.weight)
                return true;
            if(a.weight == b.weight && a.num < b.num)
                return true;
        }
        
    }
    return false;
}



vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<Boksu> bok;
    
    for(int i = 0; i < head2head.size(); i++)
    {
        int win = 0;
        int lose = 0;
        int win_weight = 0;
        double win_rate = 0;
        for(int j = 0; j < head2head.size(); j++)
        {
            if(head2head[i][j]== 'W')
            {
                win++; 
                if(weights[i] < weights[j]) //무거운 복서를 이겼는지
                    win_weight++;
            }
            else if(head2head[i][j] == 'L')
                lose++;     
        }
         //승률 계산
            if(lose == 0 && win == 0)
                win_rate = 0;
            else if(lose == 0)
                win_rate = 100;
            else
                win_rate =  (double)win / (lose + win);
        //저장
        bok.push_back({i+1, weights[i], win_rate, win_weight});
        
        sort(bok.begin(), bok.end(),cmp);
    }
    
    for(Boksu boksu : bok)
        answer.push_back(boksu.num);
    
    
  
    return answer;
}