//
//  PG_튜플_김수민.cpp
//  
//
//  Created by 김수민 on 2021/07/01.
//
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    deque<pair<int, vector<int>>> d;
    for (int i = 1; i < s.length() - 1;i++) {
        if (s[i] == '{') {
            i++;
            int cnt = 0;
            vector<int> v;

            while (s[i] != '}') {
                string ss;
                while ((s[i] != ',')&&(s[i]!='}')) {
                    cnt++;
                    char num = s[i];
                    ss += num;
                    i++;
                }
                v.push_back(stoi(ss));
                if (s[i] == ',') {
                    i++;
                }
                
            }
            d.push_back(make_pair(cnt, v));

        }
    }
    sort(d.begin(), d.end());
    answer.push_back(d[0].second[0]);
    for (int i = 1; i < d.size();i++) {
        for (int j = 0; j < answer.size();j++) {
            int num = answer[j];
            auto it = find(d[i].second.begin(), d[i].second.end(), num);
            d[i].second.erase(it);

        }
        answer.push_back(d[i].second[0]);
    }

    return answer;
}
