#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<vector<string>> tickets, string now, vector<string> &answer, bool *used, int cnt) {
    answer.push_back(now);
    if (cnt == tickets.size()) {
        return true;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if ((tickets[i][0] == now)&&(used[i]==false)) {
            used[i] = true;
            bool completed = dfs(tickets, tickets[i][1], answer, used, cnt + 1);
            if (completed) { return true; }
            used[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    bool used[10001] = { false, };
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", answer, used, 0);
    
    return answer;
}
