#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
닉네임 변경하는 방법 - 나간 후 새 닉네임, 채팅방에서 변경
*/
unordered_map<string, string> uno;
vector<pair<string, string>> v;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    int index = 0;
    string action = "";
    string id = "";
    string name = "";
    for (int i = 0; i < record.size(); i++) {
        
        if (record[i][0] == 'E' || record[i][0] == 'L') {
            action = record[i].substr(0, 5);
            index = 6;
        }
        else if (record[i][0] == 'C') {
            action = record[i].substr(0, 6);
            index = 7;
        }
        int j = index;
        if (record[i][0] != 'L') {
            for (j = index; record[i][j] != ' '; j++) {
                id += record[i][j];
            }
            name = record[i].substr(j + 1);
            if (action != "Change") v.push_back({ action, id });
            uno[id] = name;
            id = "";
        }
        else v.push_back({ action, record[i].substr(index) });
    }
    for (int i = 0; i < v.size(); i++) {
        string ans = uno[v[i].second];
        if (v[i].first == "Enter") ans += "님이 들어왔습니다.";
        else ans += "님이 나갔습니다.";
        answer.push_back(ans);
    }
    return answer;
}
