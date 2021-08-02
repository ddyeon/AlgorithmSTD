#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

//같은수가 모여있지 않으면 절반씩 쪼개나가기.
vector<vector<int>> v;
int one, zero = 0;

void dfs(int x1, int y1, int x2, int y2)
{
    int current = v[x1][y1]; //현재시작하는점

    for(int i = x1; i < x2; i++)
    {
        for(int j = y1; j < y2; j++)
        {
            if(v[i][j] != current)
            {
                dfs(x1,y1, (x1+x2)/2, (y1+y2)/2);
                dfs((x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
                dfs(x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
                dfs((x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
                return;
            }
            current = v[i][j];
        }

    }

    if(v[x1][y1] == 0)
        zero++;
    else
        one++;

    return;

}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    v = arr;
    dfs(0,0, arr.size(), arr.size());

    answer.push_back(zero);
    answer.push_back(one);

    return answer;
}

int main()
{
    //[[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]	[4,9]
}