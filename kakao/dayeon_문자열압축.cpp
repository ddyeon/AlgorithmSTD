#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for(int i = 1; i<=s.size()/2; i++)
    {
        string munja, tmp; //할때마다 초기화 필요

        int cnt = 1;
        tmp = s.substr(0,i); //찾는문자저장.

        for (int j = i; j <= s.size(); j += i)
        {
            if(tmp == s.substr(j,i))
                cnt++;
            else
            {
                if(cnt == 1)
                    munja += tmp;
                else
                    munja += to_string(cnt) + tmp;
            
            tmp = s.substr(j,i);
            cnt = 1; //다시 초기화
            }
            
        }
        if(s.size() % i != 0) //맨뒤에꺼 붙여줘야함
            munja += s.substr((s.size()/i)*i);
        
        if(answer > munja.size())
            answer = munja.size();
        
    }


    return answer;
}
