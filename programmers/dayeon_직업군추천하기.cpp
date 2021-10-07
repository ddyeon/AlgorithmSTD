#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string splitTable[10][12];

bool cmp(pair<string, int> a, pair<string, int> b){ 
    if(a.second == b.second) 
        return a.first < b.first; 
    else return a.second > b.second; 
}

void splitString(int n, string s)
{
    string tmp;
    int cur = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]!= ' ') tmp += s[i];
        else
        {
            splitTable[n][cur++] = tmp;
            tmp = "";
        }     
    }
    splitTable[n][cur] = tmp; //마지막꺼
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map <string,int> m;
    vector<pair<string,int>> v;
    
    // //개발자 선호도 저장
    // for(int i = 0; i < languages.size(); i++)
    //     m[languages[i]] = preference[i];
    
    for(int i = 0; i < table.size(); i++)
        splitString(i, table[i]);
    
    //점수계산 
    for(int i = 0; i < table.size(); i++)
    {
        string title = splitTable[i][0]; //SI
        int score = 0;
        for(int j = 0;  j < languages.size(); j++)
        {
            for(int k = 1; k <= 5; k++) {
                if(splitTable[i][k] == languages[j]) {
                    score += (6-k) * preference[j];    
                }
            }
        }
        v.push_back(make_pair(title, score));
    }
    
   //가장 높은 점수 추출
    sort(v.begin(), v.end(), cmp);
    
    answer = v[0].first;

    
    return answer;
}