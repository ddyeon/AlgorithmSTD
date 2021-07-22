//
//  main.cpp
//  soomin_스킬트리
//
//  Created by 김수민 on 2021/07/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> tmp;
    for (int i=0; i<skill.size(); i++){
        tmp[skill[i]] = i + 1;
    }
    for (auto skt:skill_trees){
        int count = 1;
        bool flag = true;
        for (int i = 0; i < skt.size(); i++){
            if (tmp[skt[i]] > count){
                flag = false;
                break;
            }
            else if (tmp[skt[i]] == count){
                count++;
            }
        }
        if (flag == true){
            answer++;
        }
    }
    return answer;
}
