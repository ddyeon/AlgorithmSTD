#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<ctype.h>
#include <map>
using namespace std;
//가질 수 있는 조합을 찾고 해당하는 경우의 수 파악
// 너무어렵다.......

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map <int,int> menuNum; //course메뉴에 해당하는 개수
    map<int, vector<string>> result; // 메뉴 갯수와 string

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
        vector<int> tmp(t_size, 0); //조합 저장

        for (int i = 0; i < course.size(); i++)
        {
            int size = course[i]; 
            if (t_size < size)  //course가 필요로하는 현재 길이보다 클 경우
                continue;

            //오름차순
            for (int j = t_size - 1; j >= t_size - size; j--)
            {
                tmp[j] = 1;
            }

            do
            {
                string t_string = ""; // 포함되어있는지 검사할 string
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
                        // 포함
                        num += 1;
                    }
                }

                if (num == 1) //안겹침
                    continue;

                if (menuNum[size] < num)
                {
                    result[size].clear();
                    menuNum[size] = num;
                    result[size].push_back(t_string);
                }
                else if (menuNum[size] == num)
                {
                    // max와 같으면 string 추가
                    result[size].push_back(t_string);
                }
            } while (next_permutation(tmp.begin(), tmp.end())); // 조합
        }
    }


    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            answer.push_back(result[i][j]);
        }
    }

    // 정렬
    sort(answer.begin(), answer.end());

    return answer;
}
