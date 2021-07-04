#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
string num = "";     //��������
vector<long long> n; //�ϼ��� ���� ����
vector<char> cal;    //���� ����
vector<char> position;

long long solution(string expression)
{
    long long answer = 0;

    for (int i = 0; i < expression.size(); i++)
    {

        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            n.push_back(stoi(num));
            cal.push_back(expression[i]);
            num = "";
        }
        else
            num += expression[i];
    }

    n.push_back(stoi(num)); //������ ����
    position = cal;         //���� ������ ���� ����
    sort(cal.begin(), cal.end());
    cal.erase(unique(cal.begin(), cal.end()), cal.end()); //�ߺ�����

    do
    {
        vector<long long> cal_num = n;
        vector<char> loc = position;
        for (int i = 0; i < cal.size(); i++)
        {
            for (int j = 0; j < loc.size(); j++)
            {
                if (cal[i] == loc[j])
                {
                    if (loc[j] == '+')
                        cal_num[j] += cal_num[j + 1];
                    else if (loc[j] == '-')
                        cal_num[j] -= cal_num[j + 1];
                    else
                        cal_num[j] *= cal_num[j + 1];

                    cal_num.erase(cal_num.begin() + j + 1);
                    loc.erase(loc.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(cal_num[0]))
            answer = abs(cal_num[0]);

    } while (next_permutation(cal.begin(), cal.end())); //������ ������ �����ִ� �Լ�
    //���� ������ ���ٸ� false ��ȯ

    return answer;
}

int main()
{
    //"50*6-3*2"
    string s = "100-200*300-500+20";
    solution(s);
}