#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
//x�� ��� 0�� �����մϴ�.
//x�� ���̸� c��� �ϸ�, x�� "c�� 2�������� ǥ���� ���ڿ�"�� �ٲ�


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
    int change = 0; //��ȯ������ ����
    int zero = 0; //������ 0�� ����

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
    // "110010101001"[3, 8]  //��ȯ������, ���ŵ� 0�� ����
    // "01110"[3, 3] 
    // "1111111"[4, 1]

    solution("110010101001");
}