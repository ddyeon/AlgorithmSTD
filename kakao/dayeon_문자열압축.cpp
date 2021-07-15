#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = s.size();

    for(int i = 1; i<=s.size()/2; i++)
    {
        string munja, tmp; //�Ҷ����� �ʱ�ȭ �ʿ�

        int cnt = 1;
        tmp = s.substr(0,i); //ã�¹�������.

        for (int j = i; j < s.size(); j += i)
        {
            if (tmp == s.substr(j, i))
                cnt++;
            else
            {
                if(cnt>1)
                    munja+= to_string(cnt);
                munja += tmp;
                tmp = s.substr(j,i);
                cnt+=1; //�������� �ٽ� �ʱ�ȭ
            }
        }
        if (cnt > 1)
            munja += to_string(cnt);

        munja += tmp;
       
        if(answer < munja.size())
            answer = munja.size();
        
    }

    return answer;
}

int main()
{
    //"aabbaccc" 7
    //"ababcdcdababcdcd" 9
    //"abcabcdede" 8
    //"abcabcabcabcdededededede" 14
    //"xababcdcdababcdcd"
    string s = "aabbaccc";
    solution(s);
}
