#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_multimap<int, string> uno;
unordered_map<string, int> v;
unordered_map<string, int> refresh;
string tmp;
int visit[11];
void dfs(string s, string g, int l) {
    if (g.size() > 1) {
        tmp = g;
        sort(tmp.begin(), tmp.end());
        if (v[tmp] != 1) {
            v[tmp] = 1;
            uno.insert({ tmp.size(), tmp });
        }
    }
    for (int i = l; i < s.size(); i++) {

        if (visit[i] == 1)continue;
        g += s[i];
        visit[i] = 1;
        dfs(s, g, i);
        visit[i] = 0;
        g.erase(g.size() - 1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        
        dfs(orders[i], "", 0);
        v = refresh;
    }
    int maxNum = 0;
    for (int i = 0; i < course.size(); i++) {
        maxNum = 0;
        for (auto j = uno.find(course[i]); j != uno.end(); ++j) {
            if (j->first != course[i])break;
            v[j->second]++;
            if (v[j->second] > maxNum) maxNum = v[j->second];
        }
        if (maxNum != 1) {
            for (auto j = v.begin(); j != v.end(); ++j) {
                if (j->second == maxNum)answer.push_back(j->first);
            }
        }
       
        v = refresh;
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main(void) {
//    solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
//    solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2,3,5 });
    solution({ "XYZ", "XWY", "WXA" }, { 2,3,4 });
}