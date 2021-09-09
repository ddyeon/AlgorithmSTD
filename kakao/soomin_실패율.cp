//
//  main.cpp
//  Kakao_실패율
//
//  Created by 김수민 on 2021/09/09.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const pair<double, int>&a, const pair<double, int>&b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map<int, int> m;
    vector<pair<int, int>> v;
    vector<pair<double, int>> tmp;
    int final = 0;
    for (int i = 0; i < stages.size(); i++){
        if (stages[i]>N){
            final += 1;
            continue;
        }
        m[stages[i]] += 1;
    }
    for (int i=0; i<N; i++){
        if (!m[i+1]){
            m[i+1] = 0;
        }
    }
    for (auto& fail : m) {
        v.push_back(make_pair(fail.first,fail.second));
    }
    sort(v.begin(), v.end());

    for (int i=0; i <v.size();i++){
        int tot = final;
        double fail = 0;
        for (int j = v.size()-1; j>=i ; j--){
            tot += v[j].second;
        }
        if (tot!=0){
       fail = static_cast<double>(v[i].second) / static_cast<double>(tot);
        }
        tmp.push_back(make_pair(fail,i+1));
    }
    sort(tmp.begin(),tmp.end(),compare);
    for (int i=0; i<tmp.size();i++){
        answer.push_back(tmp[i].second);
    }
    
    return answer;
}
