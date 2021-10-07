#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//1,2,3���� : s/d/t
//��Ÿ�� : �ش������� �� ���� 2��. ������ �ش� ���� ���̳ʽ� 
//��Ÿ��� �������� ȿ���� ��ø�Ǹ� -2��
int solution(string dartResult)
{
    int answer = 0;
    string sum = "";
    vector<int> result;
    int position = 0;

    for(int i = 0; i < dartResult.size(); i++)
    {
        char tmp = dartResult[i];
        if(tmp >= '0' && tmp <='9')
            sum += tmp;
        else if(tmp == 'S')
        {
            result.push_back(stoi(sum));
            sum = "";
            position++;

        }
        else if(tmp == 'D')
        {
            int num = stoi(sum);
            result.push_back(num*num);
            sum = "";
            position++;
        }
        else if(tmp == 'T')
        {
            int num = stoi(sum);
            result.push_back(num * num * num);
            sum = "";
            position++;
        }
        else if(tmp == '*')
        {
            if(position == 1)
                result[position-1] *= 2;
            else
            {
                result[position-1] *= 2;
                result[position-2] *= 2;
            }
            
        }
        else if(tmp == '#')
        {
            result[position-1] *= (-1);
        }
    }

    for(int i = 0; i < result.size(); i++)
    {
        answer += result[i];
    }
    return answer;
}