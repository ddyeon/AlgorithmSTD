#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
//시간 분
//각음은 1분에 한개씩
//뒤에 #확인해야함.

// struct music{
//     int time;
//     string name;
//     string code;
// };
vector <pair<string,int>> ans;
string solution(string m, vector<string> musicinfos) {
    string answer = "";
   
    vector <string> names;
    vector <string> codes;
    vector <int> time;

    for(int i = 0; i < musicinfos.size(); i++)
    {
        //시간구하기
        int start_time = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2)); //시작시간
        int end_time = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));   //시간
        time.push_back(end_time - start_time);
        int j;
        string name;
        for (j = 12; musicinfos[i][j] != ','; j++)
        {
            name += musicinfos[i][j];
        }
        names.push_back(name);

        j++;
        string code;
        for (int k = j; k < musicinfos[i].size(); k++)
        {
            code += musicinfos[i][k];
        }
        codes.push_back(code);
    }

    int max_time = 0;
    for(int i = 0; i < codes.size();i++)
    {
        string full = "";
        if(time[i] / m.size() > 0) //길이가 더크면
        {
            for(int j = 0; j < time[i]; j++)
            {
                full += codes[i][j%codes[i].size()];
            }
        }
        if(full.find(m) != string::npos)
        {
            if(time[i] > max_time)
            {
                ans.clear();
                max_time = time[i];
                ans.push_back({names[i], i});
            }
            else if(time[i] == max_time)
                ans.push_back({names[i],i});
        }
    }

    if(ans.size() == 0)
        answer = "(None)";
    else if(ans.size() == 1)
        answer = ans[0].first;
    else
    {
        sort(ans.begin(), ans.end());
        answer = ans[0].first;
    }
    


    return answer;
}

int main()
{
    //"ABCDEFG" // CDEFGABCDEFGAB - > 14분 두번
    //["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]
    //C#DEFGAB
}