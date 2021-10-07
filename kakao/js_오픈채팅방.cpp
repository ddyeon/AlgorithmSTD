#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string>m; //uid, nickname
    vector<pair<string, string>>vec; //uid, 상태
    for (int i = 0; i < record.size(); i++) {
        string uid;
        string nickname;
        if (record[i][0] == 'E') {
            int j = 6;
            for (j = 6; record[i][j] != ' '; j++)
            {
                uid += record[i][j];
            }

            for (int k = j + 1; k < record[i].size(); k++)
            {
                nickname += record[i][k];
            }

            m[uid] = nickname;
            vec.push_back(make_pair(uid, "님이 들어왔습니다."));
        }

        else if (record[i][0] == 'L') {
            int j = 6;
            for (j = 6; j < record[i].size(); j++)
            {
                uid += record[i][j];
            }
            vec.push_back(make_pair(uid, "님이 나갔습니다."));
        }

        else if (record[i][0] == 'C') {
            int j = 7;
            for (j = 7; record[i][j] != ' '; j++)
            {
                uid += record[i][j];
            }


            for (int k = j + 1; k < record[i].size(); k++)
            {
                nickname += record[i][k];
            }
            m[uid] = nickname;
        }
    }



    for (int i = 0; i < vec.size(); i++) {

        string nickname = m[vec[i].first];
        string ans = nickname + vec[i].second;
        answer.push_back(ans);
    }

    return answer;
}