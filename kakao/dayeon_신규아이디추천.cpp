#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<ctype.h>
using namespace std;

string solution(string new_id)
{
    string answer = "";

    string tmp = "";
    //1단계 소문자로 치환
    for(int i = 0; i < new_id.size(); i++)
        tmp += tolower(new_id[i]);


    //2단계
    string second = "";
    for (int i = 0; i < tmp.size(); i++)
    {
        if (isalpha(tmp[i]) != 0|| (tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '-' || tmp[i] == '_' || tmp[i] == '.')
            second += tmp[i];
        else
            continue;       
    }


    string third = "";
    int cnt = 1;
    for(int i = 0; i < second.size(); i++)
    {
        if(second[i] == '.')
        {
            int j = i+1;
            cnt = 1;
            while (true)
            {
                if(second[j]== '.')
                {
                    cnt++;
                    j++;
                }
                else
                    break;     
            }
            if(cnt >= 2) {
                third += '.';
                i +=cnt-1;
            }
            else
                third += '.';
        }
        else
        {
            third += second[i];
        }   
    }
    
    //4단계
    string four = "";
    if(third[0] == '.')
    {
        for(int i = 1; i < third.size(); i++)
        {
            four += third[i];
        }
    }
    else if (third[third.size()-1] == '.')
    {
        for (int i = 0; i < third.size()-1; i++)
        {
            four += third[i];
        }
    }
    else
      four = third;
    
    

    //5단계
    if(four.size() == 0)
        four = 'a';

    //6단계
    string six = "";
    if(four.size() >=16)
    {
        four = four.substr(0,15);

        if(four[14] == '.')
            four = four.substr(0,14);
    }

    //7단계
    if(four.size() <=2)
    {
        char tt = four[four.size()-1];
        while (true)
        {
          four += tt;
          if(four.size() ==3)
            break;
          
        }
        
    }

    answer = four;

    return answer;
}

int main()
{
    string s = "123_.def";
    solution(s);
}