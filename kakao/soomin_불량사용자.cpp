//
//  PG_불량사용자_김수민.cpp
//  
//
//  Created by 김수민 on 2021/07/01.
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    map <int, vector<string>> m;
    vector<vector<string>> banned_list;
    for (int i = 0; i < banned_id.size();i++) {
        int banned_id_size = banned_id[i].size();
        vector<string> list;
        for (int j = 0; j < user_id.size();j++) {
            if (user_id[j].size() != banned_id_size) {
                continue;
            }
            bool flag = false;
            for (int k = 0; k < banned_id_size;k++) {
                if (user_id[j][k] != banned_id[i][k]){
                    if (banned_id[i][k] == '*') {
                        continue;
                    }
                    else {
                        flag = true;
                        break;
                    }
                
                }
            }
            if (flag == false) {
                list.push_back(user_id[j]);
            }

        }
        banned_list.push_back(list);
    }
    vector<vector<string>> anw;
    int ssize=1;
    for (int i = 0; i < banned_list.size();i++) {
        ssize *= banned_list[i].size();
    }
    for (int i = 0; i <ssize;i++) {
        vector<string> tempanw;
        for (int j = 0; j < banned_list[i].size();j++) {
            m[i].push_back(banned_list[i][j]);

        }

    }
    anw.erase(unique(anw.begin(), anw.end()), anw.end());
    answer = anw.size();
    return answer;
}
