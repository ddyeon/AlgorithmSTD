#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
unordered_map<string, int> uno;
unordered_map<string, int> vuno;
int cnt;
vector<string> jaejae[9];
string path[10];
string tmp[10];
string p;
void dfs(int now, int goal) {
    if (now == goal) {
        for (int i = 0; i < goal; i++)tmp[i] = path[i];
        sort(tmp, tmp + goal);
        for (int i = 0; i < goal; i++) p += tmp[i];

        if (vuno[p] == 1) {
            p = "";
            return;
        }
        vuno[p] = 1;
        p = "";
        cnt++;
        return;
    }
    for (int i = 0; i < jaejae[now].size(); i++) {
        if (uno[jaejae[now][i]] == 1) continue;
        uno[jaejae[now][i]] = 1;
        path[now] = jaejae[now][i];
        dfs(now + 1, goal);
        path[now] = "";
        uno[jaejae[now][i]] = 0;
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int index = -1;
    for (int i = 0; i < banned_id.size(); i++) {
        index++;
        for (int j = 0; j < user_id.size(); j++) {
            if (banned_id[i].size() == user_id[j].size()) {
                int k = 0;
                for (k = 0; k < banned_id[i].size(); k++) {
                    if (banned_id[i][k] == '*')continue;
                    if (banned_id[i][k] != user_id[j][k])break;
                }
                if (k == banned_id[i].size())jaejae[index].push_back(user_id[j]);
            }
        }
    }
    dfs(0, banned_id.size());
    answer = cnt;
    return answer;
}