#include <string>
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v[501];
unordered_map<int, int> uno;

vector<int> solution(string s) {
    vector<int> answer;
    int index = 0;
    string tmp = "";
    for (int i = 2; i < s.length() - 1; i++) {
        if (tmp != "" && s[i] == ',') {
            v[index].push_back(stoi(tmp));
            tmp = "";
        }
        else if (s[i] == '}') {
            v[index].push_back(stoi(tmp));
            tmp = "";
            index++;
        }
        else if (s[i] >= '0' && s[i] <= '9')tmp += s[i];
    }
    for (int i = 1; i <= index; i++) {
        for (int j = 0; j < index; j++) {
            if (v[j].size() == i) {
                for (int k = 0; k < i;k++) {
                    if (uno[v[j][k]] == 0) {
                        answer.push_back(v[j][k]);
                        uno[v[j][k]] = 1;
                    }
                }
                break;
            }
        }
    }
    return answer;
}