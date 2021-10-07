#include <string>
#include <vector>
#include<iostream>
#include <unordered_map>
using namespace std;
unordered_map<char, int> skillmap;
unordered_map<char, int> tmp;
unordered_map<char, int> reset;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill.size(); i++) skillmap.insert({ skill[i], i + 1 });

    for (int i = 0; i < skill_trees.size(); i++) {
        bool flag = true;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            tmp.insert({ skill_trees[i][j] , j + 1 });
            if (skillmap.count(skill_trees[i][j]) != 0 && skill_trees[i][j] != skill[0]) {
                for (int k = 0; k < skillmap[skill_trees[i][j]]; k++) {
                    
                    if (tmp[skill[k]] == 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag == false) break;
        }
        if(flag==true) answer++;
        tmp = reset;
    }
    return answer;
}
int main(void) {
    cout<< solution("CBD", { "BACDE", "CBADF", "AECB","BDA" });
}
