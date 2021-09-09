//
//  main.cpp
//  Kakao_오픈채팅방
//
//  Created by 김수민 on 2021/09/09.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<int, string>> v;
    unordered_map <string,vector<vector<string>>> m;
    for (int i = 0; i < record.size(); i++) {
        istringstream ss(record[i]);
        string stringBuffer;
        vector<string> x;
        x.clear();
        while (getline(ss, stringBuffer, ' ')) {
            x.push_back(stringBuffer);
        }
        vector<string>temp;
        temp.push_back(to_string(i));
        if (x[0] == "Enter") {
            if (!m[x[1]].empty()) {
                for (int j = 0; j < m[x[1]].size(); j++) {
                        m[x[1]][j][2] = x[2];
                }
            }
            temp.push_back("Enter");
            temp.push_back(x[2]);
            m[x[1]].push_back(temp);
        }
        else if (x[0] == "Leave") {
            temp.push_back("Leave");
            temp.push_back(m[x[1]][0][2]);
            m[x[1]].push_back(temp);
        }
        else if (x[0]=="Change") {
            for (int j = 0; j < m[x[1]].size();j++) {
                    m[x[1]][j][2] = x[2];
            }
        }
        

    }
    for (auto& chat : m) {
        for (int i = 0; i < chat.second.size();i++) {
            string s = chat.second[i][2];
            s += "님이";
            if (chat.second[i][1] == "Enter") {
                s += " 들어왔습니다.";
            }
            else if (chat.second[i][1] == "Leave") {
                s += " 나갔습니다.";
            }
            v.push_back(make_pair(stoi(chat.second[i][0]), s));
        }
    }
    sort(v.begin(), v.end());
    for (int k = 0 ; k < v.size(); k++){
        answer.push_back(v[k].second);
    }

    return answer;
}
