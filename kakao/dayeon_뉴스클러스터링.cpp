#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//두집합 교집합의 크기를 합집합으로 나눈겂
//모두 공집합이면 1
//다중집합
int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    int maxvalue = 0;
    int minvalue = 0;


    //소문자로 바꾸기
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    //두글자씩 묶기
    for(int i = 0; i < str1.size(); i++)
    {
        string tmp = str1.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            v1.push_back(tmp);
    }
    for(int i = 0; i < str2.size(); i++)
    {
        string tmp = str2.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            v2.push_back(tmp);
    }

    if (v1.empty() && v2.empty())
        return 65536;

    maxvalue = v1.size() + v2.size();

    //교집합 구하기
    if (v1.size() > v2.size())
    {
        for (int i = 0; i < v2.size(); i++)
        {
            auto itr = find(v1.begin(), v1.end(), v2[i]);
            if (itr != v1.end())
            {
                minvalue++;
                v1.erase(itr);
            }
        }
    }
    else
    {
        for (int i = 0; i < v1.size(); i++)
        {
            auto itr = find(v2.begin(), v2.end(), v1[i]);
            if (itr != v2.end())
            {
                minvalue++;
                v2.erase(itr);
            }
        }
    }

    maxvalue -= minvalue; //합집합 개수

    if (maxvalue == 0)
        return 65536;

    double tmp = (double)minvalue / (double)minvalue;

    return tmp * 65536;

    return answer;
}

int main()
{
    //FRANCE	french	16384
}