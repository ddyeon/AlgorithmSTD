#include <string>
#include<algorithm>
#include <vector>
using namespace std;

bool oper(vector<string> v1, vector<string> v2) {
    if (v1[1] < v2[1])return true;
    else return false;
}

bool visit[10010];
vector<vector<string>> t;
vector<string> a;
bool dfs(string fly) {
    if (a.size() == t.size() + 1)return true;
    for (int i = 0; i < t.size(); i++) {
        if (!visit[i] && t[i][0] == fly) {
            visit[i] = 1;
            a.push_back(t[i][1]);
            if (!dfs(t[i][1])) {
                visit[i] = 0;
            }
            else return;
        }
    }
    if (a.size() != t.size()) {
        a.pop_back();
        return false;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), oper);
    t = tickets;
    a.push_back("ICN");
    dfs("ICN");
    return answer;
}
int main(void) {
    solution({ {"ICN", "AOO"}, {"AOO", "BOO"}, {"BOO", "COO"},{"COO", "DOO"},{"DOO", "EOO"},{"EOO", "DOO"},{"DOO", "COO"},{"COO", "BOO"},{"BOO", "AOO"} });
}