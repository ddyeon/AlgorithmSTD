#include <string>
#include <vector>
#include <queue>
#include<unordered_map>
using namespace std;
unordered_map<string, int> uno;
unordered_map<string, int> tmp;
queue<pair<int, int>>q;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    for (int i = 0; i < gems.size(); i++) uno[gems[i]]++;
    int i = 0, j = uno.size();
    for (int k = 0; k < uno.size(); k++) tmp[gems[k]]++;
    while (true) {
        if (uno.size() == tmp.size()) {
            q.push({ i, j });
            tmp[gems[i]]--;
            if (tmp[gems[i]] == 0) tmp.erase(gems[i]);
            i++;
            if (i == j) break;
        }
        else {
            if (j >= gems.size())continue;
            tmp[gems[j]]++;
            j++;
        }
    }
    return answer;
}
int main(void) {
    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
    solution({ "AA", "AB", "AC", "AA", "AC" });
    solution({ "XYZ", "XYZ", "XYZ" });
    solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
}