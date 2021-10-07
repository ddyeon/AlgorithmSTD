#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map <string, string> room;
    vector <vector<string>> v;

    for(int i = 0; i < record.size(); i++)
    {
        vector<string> str;
        stringstream ss(record[i]); 
        string s;
        
        while(ss >> s) //공백을 기준으로 나누기
            str.push_back(s);

        if(str[0] == "Enter" || str[0] == "Change")
            room[str[1]] = str[2]; 

        v.push_back(str);    
        
    }

    for(int i = 0; i < record.size(); i++)
    {
        string tmp = "";
        tmp += room[v[i][1]]; //아이디의 이름
        if(v[i][0] == "Enter")
            tmp += "님이 들어왔습니다.";
        else if(v[i][0] == "Leave")
            tmp +="님이 나갔습니다.";
        else
            continue;
    
        answer.push_back(tmp);
    }

    return answer;
}

int main()
{
    vector<string> v = { "Enter uid1234 Muzi",
                         "Enter uid4567 Prodo",
                         "Leave uid1234",
                         "Enter uid1234 Prodo",
                         "Change uid4567 Ryan" };

    solution(v);
}