#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<ctype.h>
#include <map>
using namespace std;
//���� �� �ִ� ������ ã�� �ش��ϴ� ����� �� �ľ�
// �ʹ���ƴ�.......

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map <int,int> menuNum; //course�޴��� �ش��ϴ� ����
    map<int, vector<string>> result; // �޴� ������ string

    for(int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
    }

    for(int i = 0; i < course.size(); i++)
    {
        menuNum[course[i]] = 1;
        vector<string> tmp;
        result[course[i]] = tmp;
    }

    while(orders.size())
    {
        string current = orders[0]; 
        orders.erase(orders.begin());

        int t_size = current.size(); 
        vector<int> tmp(t_size, 0); //���� ����

        for (int i = 0; i < course.size(); i++)
        {
            int size = course[i]; 
            if (t_size < size)  //course�� �ʿ���ϴ� ���� ���̺��� Ŭ ���
                continue;

            //��������
            for (int j = t_size - 1; j >= t_size - size; j--)
            {
                tmp[j] = 1;
            }

            do
            {
                string t_string = ""; // ���ԵǾ��ִ��� �˻��� string
                for (int j = 0; j < tmp.size(); j++)
                {
                    if (tmp[j] == 1)
                        t_string += current[j];
                }

                int num = 1; 
                for (int j = 0; j < orders.size(); j++)
                { 
                    if (includes(orders[j].begin(), orders[j].end(), t_string.begin(), t_string.end()))
                    {
                        // ����
                        num += 1;
                    }
                }

                if (num == 1) //�Ȱ�ħ
                    continue;

                if (menuNum[size] < num)
                {
                    result[size].clear();
                    menuNum[size] = num;
                    result[size].push_back(t_string);
                }
                else if (menuNum[size] == num)
                {
                    // max�� ������ string �߰�
                    result[size].push_back(t_string);
                }
            } while (next_permutation(tmp.begin(), tmp.end())); // ����
        }
    }


    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            answer.push_back(result[i][j]);
        }
    }

    // ����
    sort(answer.begin(), answer.end());

    return answer;
}
