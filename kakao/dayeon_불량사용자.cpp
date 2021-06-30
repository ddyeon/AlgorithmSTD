#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
vector<int> v[11];
bool visit[10] = {
    false,
};
set<string> s;
//중복되는 경우의 수 처리 필요.

void dfs(int cur, int n)
{
    if (cur == n)
    {
        string tmp = "";
        for (int i = 0; i < 10; i++)
            if (visit[i] == true)
                tmp += to_string(i); //경우의 수를 번호로 저장
        s.insert(tmp);
        return;
    }

    for (int j = 0; j < v[cur].size(); j++)
    {
        int now = v[cur][j];
        if (visit[now] == true)
            continue;
        visit[now] = true;
        dfs(cur + 1, n);
        visit[now] = false; //다음꺼 돌기위해 초기화
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            //길이가 다르면 검사할 필요 없음.
            if (banned_id[i].length() != user_id[j].length())
                continue;
            bool check = true;
            for (int k = 0; k < user_id[j].length(); k++)
            {
                if (banned_id[i][k] == '*')
                    continue;
                if (banned_id[i][k] == user_id[j][k])
                    continue;

                check = false; //continue안되면 다른 문자임.
                break;
            }
            if (check)
                v[i].push_back(j); //banned 인덱스에 해당하는 아이디의 인덱스 저장.
        }
    }
    dfs(0, banned_id.size());
    answer = s.size();

    return answer;
}