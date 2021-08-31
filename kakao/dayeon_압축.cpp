#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string,int> map;
    int num = 26;

    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        map[string(1, c)] = i + 1;
    }

    string s = "";

    for(int i = 0; i < msg.length();) {
        s += msg[i];
        if(map.find(s) == map.end())
        {
            map[s]= ++num;
            s.pop_back();
            answer.push_back(map[s]);
            s= "";

        }
        else
            i++;
        
    }

    answer.push_back(map[s]);


    return answer;
}

int main()
{
    
   solution("KAKAO");
}
