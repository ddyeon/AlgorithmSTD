#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

bool cmp(pair<double,int> a, pair<double,int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
    
}


vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<double,int>> v; //실패율, 인덱스

    int cnt = 0;
    int total_size = stages.size();
    for(int i = 1; i <=N; i++)
    {
        total_size = total_size - cnt;
        cnt = 0;
        for(int j = 0; j < stages.size(); j++)
        {
            if(stages[j] == i)
                cnt++;
        }
        double failure = 0;
        
        if(total_size < cnt)
            failure = 0;
        else if(cnt == 0)
            failure = 0;
        else
            failure = (double) cnt / total_size;

        //cout << failure << endl;
        v.push_back({failure, i});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].second);
        
    }



    return answer;


}

int main()
{   //N=8 , stages=[1,2,3,4,5,6,7]
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    solution(8, v);
}