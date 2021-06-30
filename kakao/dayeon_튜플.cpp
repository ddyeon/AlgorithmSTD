#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int cnt[100001] = {
        0,
    };
    //���̰� ���� ª���� �Ǿ�����
    //���帹�̳��¼��ڰ� ������
    string num = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
           num += s[i];           
        }
        else
        {
            if(num.size() >0) //�ϳ��� ����Ǿ��µ� �������̸�
            {
                cnt[stoi(num)] +=1;
                num = "";
            }
        }
        
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < 100001; i++)
    {
        if (cnt[i] != 0)
        {
            v.push_back({cnt[i], i});
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].second);
    }

    return answer;
}
int main()
{
    string s = "{{20,111},{111}}";
    solution(s);
}