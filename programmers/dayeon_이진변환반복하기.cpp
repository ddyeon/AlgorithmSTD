#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
//x의 모든 0을 제거합니다.
//x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉


string makeBinary(int num)
{
    string value = "";
    while(num >1)
    {
        if(num % 2 ==1)
            value += '1';
        else
            value += '0';
        
        num /=2;
    }
    value += '1';
    return value;
}

vector<int> solution(string s)
{
    vector<int> answer;
    int change = 0; //변환과정수 저장
    int zero = 0; //삭제된 0의 개수

    while(s!="1")
    {
        change++;
        string next_s;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]!='0')
                next_s += s[i];
        }
    
        zero += s.size() - next_s.size();

        s = makeBinary(next_s.size());
       

    }


    answer.push_back(change);
    answer.push_back(zero);



    return answer;
}

int main()
{
    // "110010101001"[3, 8]  //변환과정수, 제거된 0의 개수
    // "01110"[3, 3] 
    // "1111111"[4, 1]

    solution("110010101001");
}