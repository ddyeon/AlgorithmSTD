#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include <unordered_map>
using namespace std;
int getNum(string str1) {
    string tmp = "";
    for (int i = 0; i < str1.size(); i++) {
        if (tmp.size()!=0 && (str1[i] < '0' || str1[i] > '9'))break;       
        if (str1[i] >= '0' && str1[i] <= '9')tmp += str1[i];
        if (tmp.size() == 5)break;
    }
    return stoi(tmp);
}
string getHead(string str1) {
    string tmp = "";
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')break;
        if (str1[i] >= 'a' && str1[i] <= 'z') tmp += str1[i] - 32;
        else tmp += str1[i];
    }
    return tmp;
}
bool numoper(string str1, string str2) {
    return getNum(str1) < getNum(str2);
}
bool headoper(string str1, string str2) {
    return getHead(str1) < getHead(str2);
}
vector<string> solution(vector<string> files) {
    vector<string> answer;

    stable_sort(files.begin(), files.end(), numoper);
    stable_sort(files.begin(), files.end(), headoper);
    answer = files;
    return answer;
}
int main(void) {
    solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });
}
