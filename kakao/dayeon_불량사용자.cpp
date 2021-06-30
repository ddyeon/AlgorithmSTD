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
//�ߺ��Ǵ� ����� �� ó�� �ʿ�.

void dfs(int cur, int n)
{
    if (cur == n)
    {
        string tmp = "";
        for (int i = 0; i < 10; i++)
            if (visit[i] == true)
                tmp += to_string(i); //����� ���� ��ȣ�� ����
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
        visit[now] = false; //������ �������� �ʱ�ȭ
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            //���̰� �ٸ��� �˻��� �ʿ� ����.
            if (banned_id[i].length() != user_id[j].length())
                continue;
            bool check = true;
            for (int k = 0; k < user_id[j].length(); k++)
            {
                if (banned_id[i][k] == '*')
                    continue;
                if (banned_id[i][k] == user_id[j][k])
                    continue;

                check = false; //continue�ȵǸ� �ٸ� ������.
                break;
            }
            if (check)
                v[i].push_back(j); //banned �ε����� �ش��ϴ� ���̵��� �ε��� ����.
        }
    }
    dfs(0, banned_id.size());
    answer = s.size();

    return answer;
}